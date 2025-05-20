//FormAI DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {                   // structure for diary entry
    char date[11];               // format: yyyy-mm-dd
    char time[6];                // format: hh:mm
    char location[30];
    char notes[200];
    struct entry *next;          // pointer to next entry
};

int main() {
    struct entry *head = NULL;   // initialize linked list
    struct entry *current = NULL;
    char selection;

    while(1) {
        printf("\n-- Digital Diary Menu --\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Search entries by date\n");
        printf("4. Delete entry\n");
        printf("5. Exit program\n");
        printf("Enter your selection: ");
        scanf(" %c", &selection);
        getchar();  // to clear new line character from input buffer

        switch(selection) {
            case '1':
                printf("\n-- Add new entry --\n");
                struct entry *new_entry = (struct entry*) malloc(sizeof(struct entry));
                printf("Enter date (yyyy-mm-dd): ");
                fgets(new_entry->date, 11, stdin);
                new_entry->date[strcspn(new_entry->date, "\n")] = '\0';  // to remove new line character
                printf("Enter time (hh:mm): ");
                fgets(new_entry->time, 6, stdin);
                new_entry->time[strcspn(new_entry->time, "\n")] = '\0';
                printf("Enter location: ");
                fgets(new_entry->location, 30, stdin);
                new_entry->location[strcspn(new_entry->location, "\n")] = '\0';
                printf("Enter notes: ");
                fgets(new_entry->notes, 200, stdin);
                new_entry->notes[strcspn(new_entry->notes, "\n")] = '\0';
                new_entry->next = NULL;

                if(head == NULL) {
                    head = new_entry;   // if linked list is empty, add new entry as head
                    current = new_entry;
                } else {
                    current->next = new_entry;  // else, add new entry at the end of the list
                    current = new_entry;
                }
                printf("\nNew entry added successfully!\n");
                break;

            case '2':
                printf("\n-- View all entries --\n");
                if(head == NULL) {
                    printf("No entries found.\n");
                } else {
                    struct entry *temp = head;
                    int count = 1;
                    while(temp != NULL) {
                        printf("\nEntry #%d:\n", count);
                        printf("Date: %s\n", temp->date);
                        printf("Time: %s\n", temp->time);
                        printf("Location: %s\n", temp->location);
                        printf("Notes: %s\n", temp->notes);
                        temp = temp->next;
                        count++;
                    }
                }
                break;

            case '3':
                printf("\n-- Search entries by date --\n");
                char search_date[11];
                printf("Enter date to search (yyyy-mm-dd): ");
                fgets(search_date, 11, stdin);
                search_date[strcspn(search_date, "\n")] = '\0';

                if(head == NULL) {
                    printf("No entries found.\n");
                } else {
                    struct entry *temp = head;
                    int count = 1;
                    while(temp != NULL) {
                        if(strcmp(temp->date, search_date) == 0) {
                            printf("\nEntry #%d found:\n", count);
                            printf("Date: %s\n", temp->date);
                            printf("Time: %s\n", temp->time);
                            printf("Location: %s\n", temp->location);
                            printf("Notes: %s\n", temp->notes);
                            break;
                        }
                        temp = temp->next;
                        count++;
                    }
                    if(temp == NULL) {
                        printf("No entries found for given date.\n");
                    }
                }
                break;

            case '4':
                printf("\n-- Delete entry --\n");
                if(head == NULL) {
                    printf("No entries found.\n");
                } else {
                    char delete_date[11], delete_time[6];
                    printf("Enter date of entry to delete (yyyy-mm-dd): ");
                    fgets(delete_date, 11, stdin);
                    delete_date[strcspn(delete_date, "\n")] = '\0';
                    printf("Enter time of entry to delete (hh:mm): ");
                    fgets(delete_time, 6, stdin);
                    delete_time[strcspn(delete_time, "\n")] = '\0';
                    struct entry *temp = head;
                    struct entry *prev = NULL;
                    while(temp != NULL) {
                        if(strcmp(temp->date, delete_date) == 0 && strcmp(temp->time, delete_time) == 0) {
                            if(temp == head) {
                                head = temp->next;
                            } else {
                                prev->next = temp->next;
                            }
                            free(temp);
                            printf("\nEntry deleted successfully!\n");
                            break;
                        }
                        prev = temp;
                        temp = temp->next;
                    }
                    if(temp == NULL) {
                        printf("\nNo entries found for given date and time.\n");
                    }
                }
                break;

            case '5':
                printf("\n-- Exiting program --\n");
                return 0;

            default:
                printf("\nInvalid selection. Please try again.\n");
        }
    }
}