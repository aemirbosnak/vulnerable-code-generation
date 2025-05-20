//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char **emails;
    int num_emails;
};

void add_email(struct mailing_list *list, char *email) {
    list->emails = realloc(list->emails, (list->num_emails + 1) * sizeof(char *));
    list->emails[list->num_emails] = strdup(email);
    list->num_emails++;
}

void remove_email(struct mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            break;
        }
    }
    
    if (i < list->num_emails) {
        free(list->emails[i]);
        for (i = i + 1; i < list->num_emails; i++) {
            list->emails[i - 1] = list->emails[i];
        }
        list->num_emails--;
        list->emails = realloc(list->emails, list->num_emails * sizeof(char *));
    }
}

void print_list(struct mailing_list *list) {
    int i;
    for (i = 0; i < list->num_emails; i++) {
        printf("%s\n", list->emails[i]);
    }
}

int main() {
    struct mailing_list list;
    list.emails = NULL;
    list.num_emails = 0;
    
    char input[100];
    while (1) {
        printf("Enter a command: (add, remove, print, quit)\n");
        scanf("%s", input);
        
        if (strcmp(input, "add") == 0) {
            printf("Enter an email address: ");
            scanf("%s", input);
            add_email(&list, input);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter an email address to remove: ");
            scanf("%s", input);
            remove_email(&list, input);
        } else if (strcmp(input, "print") == 0) {
            print_list(&list);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Please enter a valid command.\n");
        }
    }
    
    return 0;
}