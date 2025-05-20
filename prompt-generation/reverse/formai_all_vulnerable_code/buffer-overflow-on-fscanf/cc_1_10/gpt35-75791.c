//FormAI DATASET v1.0 Category: Text Summarizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_SUMMARY_LEN 200

void remove_special_chars(char *str);
int count_words(char *str);
void find_frequent_words(char *str, FILE *freq_file);
void generate_summary(char *str, char *summary, FILE *freq_file);

int main()
{
    char text[1000];
    char summary[MAX_SUMMARY_LEN];
    FILE *freq_file;

    // Read the input text
    printf("Enter the text to be summarized:\n");
    fgets(text, sizeof(text), stdin);

    // Remove special characters from the text
    remove_special_chars(text);

    // Open the file containing frequent words
    freq_file = fopen("frequent_words.txt", "r");
    if (freq_file == NULL)
    {
        printf("Error opening frequent_words.txt file\n");
        exit(1);
    }

    // Generate the summary
    generate_summary(text, summary, freq_file);
    printf("\nSummary:\n%s\n", summary);

    // Close the frequency file
    fclose(freq_file);

    return 0;
}

void remove_special_chars(char *str)
{
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]) || isspace(str[i]))
        {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

int count_words(char *str)
{
    int count = 0;
    char *token = strtok(str, " ");

    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

void find_frequent_words(char *str, FILE *freq_file)
{
    char frequent_word[MAX_WORD_LEN];
    int count = 0;

    while (fscanf(freq_file, "%s %d", frequent_word, &count) == 2)
    {
        char *token = strtok(str, " ");
        while (token != NULL)
        {
            if (strcmp(frequent_word, token) == 0)
            {
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        rewind(freq_file);
    }
}

void generate_summary(char *str, char *summary, FILE *freq_file)
{
    int num_words = count_words(str);
    int max_summary_words = num_words * 0.2;
    int num_summary_words = 0;

    find_frequent_words(str, freq_file);

    char *token = strtok(str, " ");
    while (token != NULL && num_summary_words < max_summary_words)
    {
        strcat(summary, token);
        strcat(summary, " ");
        num_summary_words++;
        token = strtok(NULL, " ");
    }
    strcat(summary, "...");
}