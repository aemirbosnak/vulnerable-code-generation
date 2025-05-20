//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

int main() {
    FILE *file;
    Subscriber *subscribers = NULL;
    int numSubscribers = 0;

    file = fopen("subscribers.txt", "r");
    if (file == NULL) {
        printf("Error: could not open subscribers file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s\n", subscribers[numSubscribers].name, subscribers[numSubscribers].email)!= EOF) {
        numSubscribers++;
    }

    fclose(file);

    printf("Enter a name to search for:\n");
    char searchName[MAX_NAME_LEN];
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Subscriber *match = NULL;
    for (int i = 0; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].name, searchName) == 0) {
            match = &subscribers[i];
            break;
        }
    }

    if (match == NULL) {
        printf("No subscriber found with that name.\n");
    } else {
        printf("Subscriber found:\n");
        printf("Name: %s\n", match->name);
        printf("Email: %s\n", match->email);
    }

    return 0;
}