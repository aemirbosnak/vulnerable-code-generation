//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define a structure for each email entry
struct email_entry {
    char name[30];
    char email[50];
    struct email_entry *next;
};

//declare the head pointer of the linked list
struct email_entry *head = NULL;

//function to add email entries to the linked list
void add_email_entry() {
    //allocate memory for the new email entry
    struct email_entry *new_entry = (struct email_entry*) malloc(sizeof(struct email_entry));
    printf("Enter name: ");
    scanf("%s", new_entry->name);
    printf("Enter email: ");
    scanf("%s", new_entry->email);
    //set the next pointer to NULL as this is the last entry currently
    new_entry->next=NULL;

    //if head is null, then set the new_entry as the head entry
    if (head == NULL) {
      head = new_entry;
      printf("Email entry added successfully!\n");
    }
    else {
      // traverse the linked list till the end 
      struct email_entry* current = head;
      while(current->next!=NULL) {
          // check if the email already exists
          if(strcmp(current->email,new_entry->email)==0) {
            printf("Email already exists!\n");
            return;
          }
          current=current->next;
      }
      //adding the new email entry to the end of the linked list
      current->next=new_entry;
      printf("Email entry added successfully!\n");
    }
}

//function to delete an email entry from the linked list
void delete_email_entry() {
    char email_to_delete[50];
    printf("Enter email to delete: ");
    scanf("%s", email_to_delete);
    //if there is no email entry in the linked list
    if(head==NULL) {
        printf("No email entries found!\n");
        return;
    }
    struct email_entry* current=head;
    struct email_entry* prev=NULL;
    int found=0;//flagto check if the email entry was found
    while(current!=NULL) {
        if(strcmp(current->email,email_to_delete)==0) {
            found=1;//email entry found
            break;
        }
        prev=current;
        current=current->next;
    }
    if(found==0) {
        printf("Email entry not found!\n");
        return;
    }
    if(prev==NULL) {
        head=current->next;
        free(current);//deleting the email entry from the linked list
    }
    else {
        prev->next=current->next;
        free(current);//deleting the email entry from the linked list
    }
    printf("Email entry deleted successfully!\n");
}

//function to display all email entries in the linked list
void display_all_entries() {
    //if there is no email entry in the linked list
    if(head==NULL) {
        printf("No email entries found!\n");
        return;
    }
    struct email_entry* current=head;
    printf("List of all email entries:\n");
    while(current!=NULL) {
        printf("Name: %s, Email: %s\n",current->name,current->email);
        current=current->next;
    }
}

//function to display the count of email entries in the linked list
void display_email_entry_count() {
    //if there is no email entry in the linked list
    if(head==NULL) {
        printf("No email entries found!\n");
        return;
    }
    struct email_entry* current=head;
    int count=0;
    while(current!=NULL) {
      count++;
      current=current->next;
    }
    printf("Total email entries: %d\n",count);
}

//main function
int main() {
    int choice;
    printf("Welcome to the Email List Manager Program\n");
    do {
        printf("Choose an option from the menu:\n");
        printf("[1] Add email entry\n");
        printf("[2] Delete email entry\n");
        printf("[3] Display all email entries\n");
        printf("[4] Display email entry count\n");
        printf("[5] Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_email_entry();//add email entry function call
                break;
            case 2:
                delete_email_entry();//delete email entry function call
                break;
            case 3:
                display_all_entries();//display all email entries function call
                break;
            case 4:
                display_email_entry_count();//display email entry count function call
                break;
            case 5:
                printf("Exiting Email List Manager Program\n");
                exit(0);//exit the program
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!=5);
    return 0;
}