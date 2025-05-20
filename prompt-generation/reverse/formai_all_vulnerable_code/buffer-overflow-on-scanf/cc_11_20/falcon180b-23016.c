//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to translate alien language to English
void translate(char* alien_language) {
    // Base case: if the string is empty, return
    if (*alien_language == '\0') {
        printf(" ");
        return;
    }

    // Recursive case: call the function again with the rest of the string
    translate(alien_language + 1);

    // Print the translation of the first character
    switch (*alien_language) {
        case 'a':
            printf("apple");
            break;
        case 'b':
            printf("banana");
            break;
        case 'c':
            printf("cherry");
            break;
        case 'd':
            printf("date");
            break;
        case 'e':
            printf("elderberry");
            break;
        case 'f':
            printf("fig");
            break;
        case 'g':
            printf("grape");
            break;
        case 'h':
            printf("honeydew");
            break;
        case 'i':
            printf("kiwi");
            break;
        case 'j':
            printf("jackfruit");
            break;
        case 'k':
            printf("kumquat");
            break;
        case 'l':
            printf("lemon");
            break;
        case'm':
            printf("mango");
            break;
        case 'n':
            printf("nectarine");
            break;
        case 'o':
            printf("orange");
            break;
        case 'p':
            printf("pear");
            break;
        case 'q':
            printf("quince");
            break;
        case 'r':
            printf("raspberry");
            break;
        case's':
            printf("strawberry");
            break;
        case 't':
            printf("tangerine");
            break;
        case 'u':
            printf("watermelon");
            break;
        case 'v':
            printf("plum");
            break;
        case 'w':
            printf("grapefruit");
            break;
        case 'x':
            printf("apricot");
            break;
        case 'y':
            printf("pineapple");
            break;
        case 'z':
            printf("peach");
            break;
        default:
            printf("%c", *alien_language);
    }
}

// Main function
int main() {
    // Get the alien language string from the user
    char alien_language[100];
    printf("Enter the alien language string: ");
    scanf("%s", alien_language);

    // Call the translation function
    translate(alien_language);

    // End of program
    return 0;
}