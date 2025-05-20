//FormAI DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 100

typedef struct {
  char to[50];
  char subject[MAX_SUBJECT_LEN];
  char body[MAX_BODY_LEN];
} Email;

Email inbox[10];
int num_emails = 0;

pthread_mutex_t email_mutex = PTHREAD_MUTEX_INITIALIZER;

void *send_email(void *arg){
  Email *new_email = (Email*) arg;
  
  pthread_mutex_lock(&email_mutex);
  
  if(num_emails == 10){
    printf("Inbox is full. Email not sent.\n");
    pthread_mutex_unlock(&email_mutex);
    return NULL;
  }
  
  strcpy(inbox[num_emails].to, new_email->to);
  strcpy(inbox[num_emails].subject, new_email->subject);
  strcpy(inbox[num_emails].body, new_email->body);
  num_emails++;
  
  pthread_mutex_unlock(&email_mutex);
  
  printf("Email sent to %s:\nSubject: %s\nBody: %s\n", new_email->to, new_email->subject, new_email->body);
  
  return NULL;
}

int main(){
  pthread_t threads[5];
  int i;

  for(i=0; i<5; i++){
    Email *e = (Email*) malloc(sizeof(Email));
    printf("Enter email %d details:\n", i+1);
    printf("To: ");
    scanf("%s", e->to);
    printf("Subject: ");
    scanf("%s", e->subject);
    printf("Body: ");
    scanf("%s", e->body);
    
    pthread_create(&threads[i], NULL, send_email, (void*) e);
  }
  
  for(i=0; i<5; i++){
    pthread_join(threads[i], NULL);
  }
  
  printf("Inbox:\n");
  for(i=0; i<num_emails; i++){
    printf("Email %d:\nTo: %s\nSubject: %s\nBody: %s\n", i+1, inbox[i].to, inbox[i].subject, inbox[i].body);
  }
  
  return 0;
}