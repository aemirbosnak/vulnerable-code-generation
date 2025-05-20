//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char c_cat_language[100]; // Holds the C Cat Language input
    char human_language[1000] = ""; // Holds the translated sentence in English

    printf("\n\nWelcome to the C Cat Language Translator!!!\n");
    printf("Please enter your C Cat Language sentence below:\n");
    scanf("%[^\n]s", c_cat_language); // Getting the input sentence with whitespace

    int len = strlen(c_cat_language);

    // Translating C Cat Language to English
    for (int i = 0; i < len; i++) {

        // If the current character is a 'purr', replace it with 'I'
        if (c_cat_language[i] == 'p') {
            strcat(human_language, "I");
        } 
        // If the current character is a 'meow', replace it with 'am'
        else if (c_cat_language[i] == 'm') { 
            strcat(human_language, "am");
        }
        // If the current character is a 'taste', replace it with 'enjoy'
        else if (c_cat_language[i] == 't') {
            strcat(human_language, "enjoy");
        }
        // If the current character is a 'scratch', replace it with 'like'
        else if (c_cat_language[i] == 's') {
            strcat(human_language, "like");
        }
        // If the current character is a 'pounce', replace it with 'love'
        else if (c_cat_language[i] == 'c') {
            strcat(human_language, "love");
        }
        // If none of the above, leave the character as is
        else {
            char temp[2];
            temp[0] = c_cat_language[i];
            temp[1] = '\0';
            strcat(human_language, temp);
        }
    }

    printf("\n\nThe translated sentence in English is:\n\n");

    // Capitalizing the first letter of the translated sentence
    if (human_language[0] >= 97 && human_language[0] <= 122) {
        human_language[0] -= 32;
    }

    printf("%s.\n\n", human_language);
    printf("Thank you for using the C Cat Language Translator!\n\n");

    return 0;
}