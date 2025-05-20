//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void reverse_string(char str[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void capitalize_string(char str[]) {
    int i;

    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void remove_whitespace(char str[]) {
    int i, j;

    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void remove_punctuation(char str[]) {
    int i, j;

    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!ispunct(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    char str[MAX_LEN];
    int choice;

    printf("Enter a string: ");
    scanf("%s", str);

    do {
        printf("\n1. Reverse string\n2. Capitalize string\n3. Remove whitespace\n4. Remove punctuation\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverse_string(str);
                printf("Reversed string: %s\n", str);
                break;
            case 2:
                capitalize_string(str);
                printf("Capitalized string: %s\n", str);
                break;
            case 3:
                remove_whitespace(str);
                printf("String without whitespace: %s\n", str);
                break;
            case 4:
                remove_punctuation(str);
                printf("String without punctuation: %s\n", str);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}