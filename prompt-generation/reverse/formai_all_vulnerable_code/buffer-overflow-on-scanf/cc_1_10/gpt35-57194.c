//FormAI DATASET v1.0 Category: Mailing list manager ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct email{
  char email_address[MAX_SIZE];
  struct email *next;
}Email;

Email* createEmail(char* address){
  Email *newEmail= (Email*)malloc(sizeof(Email));
  if(newEmail!=NULL){
    strcpy(newEmail->email_address, address);
    newEmail->next=NULL;
  }
  return newEmail;
}

Email* createList(char* address){
  Email *head=createEmail(address);
  return head;
}

void addEmail(Email** head, char* address){
  if(*head==NULL){
    *head=createEmail(address);
  }
  else{
    Email *temp=*head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    Email *newEmail=createEmail(address);
    temp->next=newEmail;
  }
}

void deleteEmail(Email** head, char* address){
  if(*head==NULL){
    printf("Mailing list is empty!\n");
  }
  else{
    Email *temp=*head;
    Email *prev=NULL;
    while(temp!=NULL){
      if(strcmp(temp->email_address, address)==0){
        if(prev==NULL){
          *head=temp->next;
        }
        else{
          prev->next=temp->next;
        }
        free(temp);
        printf("%s has been removed from the mailing list!\n", address);
        return;
      }
      prev=temp;
      temp=temp->next;
    }
    printf("%s was not found in the mailing list.\n", address);
  }
}

void printList(Email* head){
  Email *temp=head;
  if(temp==NULL){
    printf("Mailing list is empty!\n");
  }
  else{
    printf("Mailing List:\n");
    while(temp!=NULL){
      printf("%s\n", temp->email_address);
      temp=temp->next;
    }
  }
}

void saveList(Email* head, char *filename){
  Email *temp=head;
  FILE *fp;
  fp=fopen(filename, "w");
  if(fp!=NULL){
    while(temp!=NULL){
      fprintf(fp, "%s\n", temp->email_address);
      temp=temp->next;
    }
    fclose(fp);
    printf("Mailing list has been saved!\n");
  }
  else{
    printf("Error occurred while opening file!\n");
  }
}

void loadList(Email** head, char* filename){
  FILE *fp;
  fp=fopen(filename, "r");
  if(fp!=NULL){
    char buffer[MAX_SIZE];
    while(fgets(buffer, MAX_SIZE, fp)!=NULL){
      buffer[strcspn(buffer, "\n")]=0;
      addEmail(head, buffer);
    }
    fclose(fp);
    printf("Mailing list has been loaded!\n");
  }
  else{
    printf("Error occurred while opening file!\n");
  }
}

int main(){
  Email *head=NULL;
  int choice=0;
  char address[MAX_SIZE];
  char filename[MAX_SIZE];
  printf("Welcome to the Mailing List Program!\n");
  while(choice!=6){
    printf("\n");
    printf("Choose an option:\n");
    printf("1. Create a mailing list\n");
    printf("2. Add an email address\n");
    printf("3. Delete an email address\n");
    printf("4. View mailing list\n");
    printf("5. Save mailing list\n");
    printf("6. Load mailing list\n");
    printf("7. Exit\n");
    printf("> ");
    scanf("%d", &choice);
    printf("\n");
    switch(choice){
      case 1:
        if(head==NULL){
          printf("Enter the email address: ");
          scanf("%s", address);
          head=createList(address);
          printf("Mailing list created!\n");
        }
        else{
          printf("Mailing list already exists!\n");
        }
        break;
      case 2:
        printf("Enter the email address: ");
        scanf("%s", address);
        addEmail(&head, address);
        printf("%s has been added to the mailing list!\n", address);
        break;
      case 3:
        printf("Enter the email address: ");
        scanf("%s", address);
        deleteEmail(&head, address);
        break;
      case 4:
        printList(head);
        break;
      case 5:
        printf("Enter file name: ");
        scanf("%s", filename);
        saveList(head, filename);
        break;
      case 6:
        printf("Enter file name: ");
        scanf("%s", filename);
        loadList(&head, filename);
        break;
      case 7:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }
  Email *temp=head;
  while(head!=NULL){
    temp=head;
    head=head->next;
    free(temp);
  }
  return 0;
}