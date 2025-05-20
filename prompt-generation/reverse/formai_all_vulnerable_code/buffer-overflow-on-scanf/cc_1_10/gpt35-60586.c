//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include<stdio.h>
#include<string.h>

// Function declarations
void display_menu();
void translate_to_cat_lang(char sentence[]);
void translate_to_english(char sentence[]);

// Main function
int main()
{
    int choice;
    char sentence[100];

    do
    {
        display_menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("\nEnter a sentence to translate to Cat Language: ");
                    scanf(" %[^\n]s", sentence);
                    translate_to_cat_lang(sentence);
                    break;

            case 2: printf("\nEnter a sentence to translate to English: ");
                    scanf(" %[^\n]s", sentence);
                    translate_to_english(sentence);
                    break;

            case 3: printf("\nExiting program...\n");
                    break;

            default: printf("\nInvalid Choice\n");
        }

    }while(choice != 3);

    return 0;
}


// Function to display the menu
void display_menu()
{
    printf("\n\nCAT LANGUAGE TRANSLATOR\n");
    printf("1. Translate to Cat Language\n");
    printf("2. Translate to English\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}


// Function to translate to cat language
void translate_to_cat_lang(char sentence[])
{
    char cat_sentence[100] = "";
    int i, j;

    for(i = 0; i < strlen(sentence); i++)
    {
        if(sentence[i] == ' ')  // If space is encountered
            strcat(cat_sentence, "meow ");  // Replace with "meow"
        else
            if(i%2 == 0)
                cat_sentence[strlen(cat_sentence)] = sentence[i];  // Copy the character as it is
    }

    printf("\nTranslated Sentence: %s\n", cat_sentence);
}


// Function to translate to english
void translate_to_english(char sentence[])
{
    char english_sentence[100] = "";
    int i, j = 0;

    for(i = 0; i < strlen(sentence); i++)
    {
        if(sentence[i] == 'm' && sentence[i+1] == 'e' && sentence[i+2] == 'o' && sentence[i+3] == 'w')  // If "meow" is encountered
        {
            english_sentence[j] = ' ';  // Add space
            i = i + 3;
        }
        else
            if(i%2 == 0)
            {
                english_sentence[j] = sentence[i];  // Copy the character as it is
                j++;
            }
    }

    printf("\nTranslated Sentence: %s\n", english_sentence);
}