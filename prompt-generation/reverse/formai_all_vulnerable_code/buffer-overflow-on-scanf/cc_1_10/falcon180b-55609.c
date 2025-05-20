//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *string;
    int length;
} String;

String strings[MAX_SIZE];
int numStrings = 0;

void addString(char *str) {
    if (numStrings >= MAX_SIZE) {
        printf("Error: Maximum number of strings reached.\n");
        return;
    }
    strings[numStrings].string = strdup(str);
    strings[numStrings].length = strlen(str);
    numStrings++;
}

int searchStrings(char *str) {
    int i;
    for (i = 0; i < numStrings; i++) {
        if (strcmp(strings[i].string, str) == 0) {
            printf("String found at index %d.\n", i);
            return i;
        }
    }
    printf("String not found.\n");
    return -1;
}

int main() {
    int choice;
    char str[100];
    do {
        printf("1. Add string\n");
        printf("2. Search strings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter string to add: ");
                scanf("%s", str);
                addString(str);
                break;
            case 2:
                printf("Enter string to search for: ");
                scanf("%s", str);
                searchStrings(str);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}