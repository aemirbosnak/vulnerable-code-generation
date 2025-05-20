//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function
int main() {
  // Declare the variables
  char name[50], email[50], phone[50], skills[100];
  int age, experience;

  
  printf("\n\n___________________________________-\n");
  printf("\t** Resume Parsing System **\n");
  printf("___________________________________-\n\n");

  
  printf("Enter your name: ");
  scanf("%s", name);

  
  printf("Enter your email address: ");
  scanf("%s", email);

  
  printf("Enter your phone number: ");
  scanf("%s", phone);

  
  printf("Enter your age: ");
  scanf("%d", &age);

  
  printf("Enter your years of experience: ");
  scanf("%d", &experience);

  
  printf("Enter your skills (comma-separated): ");
  scanf(" %[^\n]%*c", skills); 

  
  printf("\n\n___________________________________-\n");
  printf("\t** Resume **\n");
  printf("___________________________________-\n\n");

  
  printf("Name: %s\n", name);
  printf("Email: %s\n", email);
  printf("Phone: %s\n", phone);
  printf("Age: %d\n", age);
  printf("Experience: %d years\n", experience);
  printf("Skills: %s\n", skills);

  return 0;
}