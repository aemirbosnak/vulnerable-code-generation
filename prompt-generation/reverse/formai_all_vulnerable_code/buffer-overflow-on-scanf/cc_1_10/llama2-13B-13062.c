//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50

// Declare a knight to hold the string
typedef struct Knight {
    char name[MAX_STRING_LENGTH];
    int strength;
} Knight;

// Function to knightify a string
void knightify(char *str) {
    // Check if the string is too long
    if (strlen(str) > MAX_STRING_LENGTH) {
        printf("Thy string is too long, good sir/madam!\n");
        return;
    }

    // Convert the string to uppercase
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }

    // Add a medieval flair
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            str[i] = 'th';
        }
    }

    // Print the knightified string
    printf("Hail, %s the %s!\n", str, str);
}

int main() {
    // Declare a knight
    Knight knight = {"Sir", 10};

    // Ask the user for a string
    printf("Pray tell, what is thy name? ");
    char name[50];
    scanf("%s", name);

    // Knightify the string
    knightify(name);

    // Print the knight's name
    printf("Greetings, %s the %s!\n", knight.name, knight.name);

    return 0;
}