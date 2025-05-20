//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_num[15];
} Contact;

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    printf("Greetings, my dear Watson! Let us create a phone book to keep track of our contacts.\n");

    while (1) {
        printf("Do you wish to add a contact? (y/n) ");
        char answer[2];
        scanf("%s", answer);

        if (strcmp(answer, "y") == 0) {
            if (num_contacts == MAX_CONTACTS) {
                printf("Alas, our phone book is full! We cannot add any more contacts.\n");
                continue;
            }

            printf("Please enter the name of the contact: ");
            scanf("%s", contacts[num_contacts].name);

            printf("Please enter the phone number of the contact: ");
            scanf("%s", contacts[num_contacts].phone_num);

            num_contacts++;
        } else if (strcmp(answer, "n") == 0) {
            printf("Very well, my dear Watson. Here are the contacts we have in our phone book:\n\n");

            for (int i = 0; i < num_contacts; i++) {
                printf("%s: %s\n", contacts[i].name, contacts[i].phone_num);
            }

            printf("\nUntil next time, my dear Watson!\n");
            break;
        } else {
            printf("I beg your pardon, Watson? I did not quite understand what you said.\n");
        }
    }

    return 0;
}