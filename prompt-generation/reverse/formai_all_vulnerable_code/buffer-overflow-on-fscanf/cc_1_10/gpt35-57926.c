//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000

struct words
{
    char word[30];
    int frequency;
};

typedef struct words Words;

void print_menu()
{
    printf("\n");
    printf("===============================================\n");
    printf("           Welcome to Word Frequency Counter!");
    printf("\n");
    printf("===============================================\n\n");
    printf("Please choose an option:\n");
    printf("[1] Enter text\n");
    printf("[2] Load text from file\n");
    printf("[3] View word frequency count\n");
    printf("[4] Clear all data\n");
    printf("[5] Exit program\n");

}

void load_text(char text[MAX], char filepath[MAX])
{
    FILE *fptr;

    fptr = fopen(filepath, "r");

    if(fptr == NULL)
    {
        printf("Error loading file.");
        return;
    }

    fscanf(fptr, "%[^\n]s", text);

    printf("File loaded successfully!\n");

    fclose(fptr);

}

void enter_text(char text[MAX])
{
    printf("Please enter the text:\n");

    fflush(stdin);

    scanf("%[^\n]s", text);

    printf("Text entered successfully!\n");
}

void remove_special_characters(char *text)
{
    int i, j;

    for(i = 0; text[i] != '\0'; i++)
    {
        while (!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122) || text[i] == '\0'))
        {
            for(j = i; text[j] != '\0'; j++)
            {
                text[j] = text[j + 1];
            }

            text[j] = '\0';
        }
    }
}

int validate_word(char word[])
{
    int i;

    for(i = 0; word[i] != '\0'; i++)
    {
        if (!(word[i] >= 65 && word[i] <= 90) && !(word[i] >= 97 && word[i] <= 122))
        {
            return 0;
        }
    }

    return 1;
}

int find_word(Words words[], char word[])
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        if(strcmp(words[i].word, word) == 0)
        {
            return i;
        }

        if(words[i].frequency == 0)
        {
            strcpy(words[i].word, word);
            return i;
        }
    }

    return -1;
}

void count_words(Words words[], char *text)
{
    char *word;
    int i = 0, index;

    word = strtok(text, " ");

    while(word != NULL)
    {
        if(validate_word(word))
        {
            index = find_word(words, word);
            words[index].frequency++;
        }

        word = strtok(NULL, " ");
        i++;
    }

    printf("Word Count: %d\n", i);
}

void print_words(Words words[])
{
    int i;

    printf("WORD FREQUENCY:\n");

    for(i = 0; i < MAX; i++)
    {
        if(words[i].frequency != 0)
        {
            printf("%-15s%d\n", words[i].word, words[i].frequency);
        }
    }

    printf("\n");
}

void clear_words(Words words[])
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        strcpy(words[i].word, "\0");
        words[i].frequency = 0;
    }

    printf("Data cleared!\n");
}

int main()
{
    int choice;
    Words words[MAX];
    char text[MAX], filepath[MAX];

    while(1)
    {
        print_menu();

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enter_text(text);
                remove_special_characters(text);
                count_words(words, text);
                break;

            case 2:
                printf("Enter file path: ");
                fflush(stdin);
                scanf("%[^\n]s", filepath);
                load_text(text, filepath);
                remove_special_characters(text);
                count_words(words, text);
                break;

            case 3:
                print_words(words);
                break;

            case 4:
                clear_words(words);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}