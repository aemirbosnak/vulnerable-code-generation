//FormAI DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
} contact;

int main() {
  contact *mailing_list = malloc(sizeof(contact));
  int num_contacts = 0;
  char choice;

  printf("Welcome to the mailing list manager!\n");
  printf("Enter 'a' to add a contact, 'p' to print the list, or 'q' to quit.\n");

  do {
    printf("> ");
    scanf(" %c", &choice);

    switch(choice) {
      case 'a':
        // resize the mailing list
        num_contacts++;
        mailing_list = realloc(mailing_list, sizeof(contact) * num_contacts);
        // prompt user for contact info
        printf("Enter name: ");
        scanf("%s", mailing_list[num_contacts - 1].name);
        printf("Enter email: ");
        scanf("%s", mailing_list[num_contacts - 1].email);
        break;
      case 'p':
        // print each contact in the mailing list
        for(int i = 0; i < num_contacts; i++) {
          printf("%s <%s>\n", mailing_list[i].name, mailing_list[i].email);
        }
        break;
      case 'q':
        // quit the program
        printf("Goodbye!\n");
        break;
      default:
        // invalid input
        printf("Invalid choice.\n");
        break;
    }
  } while(choice != 'q');

  free(mailing_list);
  return 0;
}