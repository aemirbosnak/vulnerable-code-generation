//FormAI DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mail{
  char name[50];
  char email[100];
  struct Mail * next;
};

struct Mail * firstMail = NULL;
struct Mail * lastMail = NULL;

void addMail(char name[], char email[]){ // function to add new email data to the list
  struct Mail * newMail = (struct Mail*) malloc(sizeof(struct Mail)); // allocating memory dynamically for new data
  strcpy(newMail->name, name);
  strcpy(newMail->email, email);
  newMail->next = NULL;

  if (firstMail == NULL){ // case when the list is empty
    firstMail = newMail;
    lastMail = newMail;
  } else { // case when the list has some data already
    lastMail->next = newMail;
    lastMail = newMail;
  }
}

void printList(){ // function to print all the emails in the list
  struct Mail * current = firstMail;
  while(current != NULL){ // iterating through the list
    printf("Name: %s\n", current->name);
    printf("Email: %s\n", current->email);
    current = current->next;
  }
}

int main(){
  int choice;
  char name[50];
  char email[100];

  do{ // main menu to take input from user
    printf("\nChoose an option:\n");
    printf("1. Add a new email\n");
    printf("2. Print all emails\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);
        addMail(name, email); // calling the function to add new email
        printf("Email added successfully!\n");
        break;
      case 2:
        printList(); // calling the function to print the emails
        break;
      case 3:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 3);

  return 0;
}