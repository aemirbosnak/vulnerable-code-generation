//FormAI DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct MailingList {
   char name[MAX_SIZE];
   char email[MAX_SIZE];
   char phone_number[MAX_SIZE];
};

void addToList(struct MailingList* ptr, int numRecords);
void displayList(struct MailingList* ptr, int numRecords);
void deleteFromList(struct MailingList* ptr, int* numRecords);

int main()
{
    int choice, numRecords = 0;
    struct MailingList list[MAX_SIZE];
    do {
        printf("Enter 1 to add a contact\n");
        printf("Enter 2 to display contacts\n");
        printf("Enter 3 to delete a contact\n");
        printf("Enter 4 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addToList(list, numRecords);
            numRecords++;
            break;
        case 2:
            displayList(list, numRecords);
            break;
        case 3:
            deleteFromList(list, &numRecords);
            break;
        }
    } while (choice != 4);
    return 0;
}

void addToList(struct MailingList* ptr, int numRecords)
{
    printf("Enter name: ");
    scanf("%s", ptr[numRecords].name);
    printf("Enter email: ");
    scanf("%s", ptr[numRecords].email);
    printf("Enter phone number: ");
    scanf("%s", ptr[numRecords].phone_number);
}

void displayList(struct MailingList* ptr, int numRecords)
{
    if (numRecords == 0) {
        printf("No contacts found\n");
        return;
    }
    printf("Name\tEmail\tPhone number\n");
    for (int i=0; i<numRecords; i++) {
        printf("%s\t%s\t%s\n", ptr[i].name, ptr[i].email, ptr[i].phone_number);
    }
}

void deleteFromList(struct MailingList* ptr, int* numRecords)
{
    char email[MAX_SIZE];
    printf("Enter email of contact to delete: ");
    scanf("%s", email);
    int found = 0;
    for (int i=0; i<*numRecords; i++) {
        if (strcmp(ptr[i].email, email) == 0) {
            found = 1;
            for (int j=i; j<*numRecords-1; j++) {
                strcpy(ptr[j].name, ptr[j+1].name);
                strcpy(ptr[j].email, ptr[j+1].email);
                strcpy(ptr[j].phone_number, ptr[j+1].phone_number);
            }
            (*numRecords)--;
            break;
        }
    }
    if (!found) {
        printf("Contact not found\n");
    }
}