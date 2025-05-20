//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024

void print_string(const char *str);
void reverse_string(char *str);
void repeat_string(char *str, int count);
void capitalize_string(char *str);

int main() {
    char str[MAX_STR_LEN];
    int choice;

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    printf("Available string manipulation options:\n");
    printf("1. Reverse the string\n");
    printf("2. Repeat the string %d times\n", MAX_STR_LEN);
    printf("3. Capitalize the first letter of the string\n");

    do {
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverse_string(str);
                break;
            case 2:
                repeat_string(str, MAX_STR_LEN);
                break;
            case 3:
                capitalize_string(str);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);

    print_string(str);

    return 0;
}

void print_string(const char *str) {
    printf("%s\n", str);
}

void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void repeat_string(char *str, int count) {
    int i;

    for (i = 0; i < count; i++) {
        strcat(str, str);
    }
}

void capitalize_string(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}