//FormAI DATASET v1.0 Category: Email Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BODY_SIZE 1000
#define MAX_EMAIL_SIZE 1200
#define MAX_SUBJECT_SIZE 100
#define MAX_SENDER_NAME_SIZE 100
#define MAX_SENDER_EMAIL_SIZE 100
#define MAX_RECIPIENT_NAME_SIZE 100
#define MAX_RECIPIENT_EMAIL_SIZE 100

void send_email(char* sender_name, char* sender_email, char* recipient_name, char* recipient_email, char* subject, char* body) {
  char email[MAX_EMAIL_SIZE];
  int i = 0;
  
  // Add sender name
  for(i = 0; i < MAX_SENDER_NAME_SIZE && sender_name[i] != '\0'; i++) {
    email[i] = sender_name[i];
  }
  email[i++] = ' ';
  
  // Add sender email
  for(int j = 0; j < MAX_SENDER_EMAIL_SIZE && sender_email[j] != '\0'; j++, i++) {
    email[i] = sender_email[j];
  }
  email[i++] = '\n';
  
  // Add recipient name
  for(int j = 0; j < MAX_RECIPIENT_NAME_SIZE && recipient_name[j] != '\0'; j++, i++) {
    email[i] = recipient_name[j];
  }
  email[i++] = ' ';
  
  // Add recipient email
  for(int j = 0; j < MAX_RECIPIENT_EMAIL_SIZE && recipient_email[j] != '\0'; j++, i++) {
    email[i] = recipient_email[j];
  }
  email[i++] = '\n';
  
  // Add subject
  for(int j = 0; j < MAX_SUBJECT_SIZE && subject[j] != '\0'; j++, i++) {
    email[i] = subject[j];
  }
  email[i++] = '\n';
  
  // Add body
  for(int j = 0; j < MAX_BODY_SIZE && body[j] != '\0'; j++, i++) {
    email[i] = body[j];
  }
  email[i] = '\0';
  
  // Send the email
  printf("Email sent successfully:\n %s\n", email);
}

int main() {
  char sender_name[MAX_SENDER_NAME_SIZE] = "John Smith";
  char sender_email[MAX_SENDER_EMAIL_SIZE] = "johnsmith@gmail.com";
  char recipient_name[MAX_RECIPIENT_NAME_SIZE] = "Jane Doe";
  char recipient_email[MAX_RECIPIENT_EMAIL_SIZE] = "janedoe@gmail.com";
  char subject[MAX_SUBJECT_SIZE] = "Confidential Information";
  char body[MAX_BODY_SIZE] = "Hello Jane,\n\nI have some confidential information to share with you. Can you meet me at the park at 5pm today?\n\nBest regards,\nJohn";
  
  // Check for malicious code
  if(strstr(subject, "hack") != NULL || strstr(body, "<script>") != NULL) {
    printf("Malicious code detected. Email cannot be sent.\n");
    exit(1);
  }
  
  // Check for suspicious words in subject and body
  char* suspicious_words[] = {"confidential", "secret", "private"};
  for(int i = 0; i < sizeof(suspicious_words) / sizeof(char*); i++) {
    if(strstr(subject, suspicious_words[i]) != NULL || strstr(body, suspicious_words[i]) != NULL) {
      printf("Suspicious words detected in subject or body. Are you sure you want to send this email? (y/n) ");
      char response;
      scanf("%c", &response);
      if(response != 'y') {
        printf("Email not sent.\n");
        exit(0);
      }
    }
  }
  
  // Finally, send the email
  send_email(sender_name, sender_email, recipient_name, recipient_email, subject, body);
  
  return 0;
}