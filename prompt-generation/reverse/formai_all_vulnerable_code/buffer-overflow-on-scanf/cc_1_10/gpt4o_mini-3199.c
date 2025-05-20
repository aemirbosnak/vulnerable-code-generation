//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void changeCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int countVowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

void displayMenu() {
    printf("Welcome to the Surprising String Manipulation Utility!\n");
    printf("Choose an option to manipulate your string:\n");
    printf("1. Reverse the string\n");
    printf("2. Change case of the string\n");
    printf("3. Count vowels in the string\n");
    printf("4. Exit\n");
}

int main() {
    char str[MAX_LENGTH];
    int choice;

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0; // Removes the trailing newline character

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You chose to reverse the string!\n");
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 2:
                printf("You chose to change the case of the string!\n");
                changeCase(str);
                printf("String after changing case: %s\n", str);
                break;
            case 3:
                printf("You chose to count vowels in the string!\n");
                int vowels = countVowels(str);
                printf("The string contains %d vowels.\n", vowels);
                break;
            case 4:
                printf("Exiting! Have a surprising day!\n");
                break;
            default:
                printf("Hmm... That's not a valid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}