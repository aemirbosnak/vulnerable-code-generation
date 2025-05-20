//FormAI DATASET v1.0 Category: Digital Diary ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ENTRIES 100

// Function for password protection
int password() {
    int pin;
    printf("\nEnter password to view the diary: ");
    scanf("%d",&pin);

    if(pin == 1234) {
        printf("\nCorrect password!\n");
        return 1;
    }
    else {
        printf("\nIncorrect password.\n");
        return 0;
    }
}

// Structure for diary entries
typedef struct {
    char date[20];
    char entry[500];
} Entry;

int main() {
    Entry diary[MAX_ENTRIES];
    int num_entries = 0;
    int choice, view, i;

    while(1) {
        printf("\n\nDigital Diary Menu: ");
        printf("\n1. Add New Entry");
        printf("\n2. View Existing Entry");
        printf("\n3. Quit Program");
        printf("\nEnter your choice (1/2/3): ");
        scanf("%d",&choice);

        if(choice == 1) {
            if(num_entries < MAX_ENTRIES) {
                printf("\nEnter the Date for the entry (dd/mm/yyyy): ");
                scanf("%s",diary[num_entries].date);
                getchar();

                printf("\nEnter the new Diary Entry:\n");
                fgets(diary[num_entries].entry, 500, stdin);

                printf("\nEntry successfully added!\n");
                num_entries++;
            }
            else {
                printf("\nDiary is full!\n");
            }
        }

        else if(choice == 2) {
            if(password()) {
                printf("\nEnter the entry number you want to view (1-%d): ",num_entries);
                scanf("%d",&view);

                if(view >= 1 && view <= num_entries) {
                    printf("\nDate of Entry: %s\n",diary[view-1].date);
                    printf("\n%s\n",diary[view-1].entry);
                }

                else {
                    printf("\nEntry not found!\n");
                }
            }
        }

        else if(choice == 3) {
            printf("\nQuitting program...\n");
            break;
        }

        else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}