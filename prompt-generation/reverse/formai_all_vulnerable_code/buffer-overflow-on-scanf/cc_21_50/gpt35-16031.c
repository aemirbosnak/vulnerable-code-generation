//FormAI DATASET v1.0 Category: Data validation ; Style: innovative
#include <stdio.h>
#include <ctype.h>

int main() {
  char name[50], address[100], phone[20], email[50];
  int age;
  char c;
  printf("Enter your name: ");
  fgets(name, 50, stdin);
  printf("Enter your age: ");
  scanf("%d", &age);
  printf("Enter your address: ");
  fgets(c, 1, stdin); // clears input buffer
  fgets(address, 100, stdin);
  printf("Enter your phone number: ");
  fgets(phone, 20, stdin);
  printf("Enter your email: ");
  fgets(email, 50, stdin);

  // Validate name
  int valid_name = 1;
  for(int i=0; i<strlen(name); i++) {
    if(!isalpha(name[i]) && !isspace(name[i])) {
      valid_name = 0;
      break;
    }
  }

  // Validate age
  int valid_age = 1;
  if(age < 18 || age > 120) {
    valid_age = 0;
  }

  // Validate address
  int valid_address = 1;
  if(strlen(address) > 100) {
    valid_address = 0;
  }

  // Validate phone number
  int valid_phone = 1;
  if(strlen(phone) != 10) {
    valid_phone = 0;
  } else {
    for(int i=0; i<strlen(phone); i++) {
      if(!isdigit(phone[i])) {
        valid_phone = 0;
        break;
      }
    }
  }

  // Validate email
  int valid_email = 1;
  if(strlen(email) > 50) {
    valid_email = 0;
  } else {
    int at_count = 0, dot_count = 0;
    for(int i=0; i<strlen(email); i++) {
      if(email[i] == '@') {
        at_count++;
      } else if(email[i] == '.') {
        dot_count++;
      }
    }
    if(at_count != 1 || dot_count != 1) {
      valid_email = 0;
    }
  }

  // Print results
  if(valid_name && valid_age && valid_address && valid_phone && valid_email) {
    printf("\nSuccessfully validated data!\n");
  } else {
    printf("\nValidation failed. Errors:\n");
    if(!valid_name) printf("- Invalid name (alphabetical characters and spaces only)\n");
    if(!valid_age) printf("- Invalid age (must be between 18 and 120)\n");
    if(!valid_address) printf("- Invalid address (maximum length is 100 characters)\n");
    if(!valid_phone) printf("- Invalid phone number (must be 10 digits)\n");
    if(!valid_email) printf("- Invalid email address (must contain exactly one @ and one .)\n");
  }

  return 0;
}