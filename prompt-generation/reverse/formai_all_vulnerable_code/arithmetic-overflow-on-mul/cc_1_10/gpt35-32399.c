//FormAI DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000 // Maximum allowed input size
#define MAX_OUTPUT_SIZE 100 // Maximum allowed output size

int count_words(char *input); // Function to count number of words in input string
void tokenize_input(char *input, char *words[]); // Function to split input into separate words
void summarize_text(char *input, char *output[], int num_sentences, int num_words); // Function to summarize text

int main()
{
    char input[MAX_INPUT_SIZE]; // Input text
    char *output[MAX_OUTPUT_SIZE]; // Output summary sentences
    int num_sentences, num_words; // Number of sentences to include in summary and maximum number of words per sentence, respectively

    // Get user input
    printf("Enter text to summarize (max %d chars):\n", MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Get summary parameters
    printf("Enter number of sentences for summary: ");
    scanf("%d", &num_sentences);
    printf("Enter maximum number of words per sentence: ");
    scanf("%d", &num_words);

    // Remove trailing newline character from input
    input[strlen(input) - 1] = '\0';

    // Summarize input text
    summarize_text(input, output, num_sentences, num_words);

    // Display output summary
    printf("\nSummary:\n");
    for (int i = 0; i < num_sentences; i++)
    {
        if (output[i] != NULL)
        {
            printf("%s\n", output[i]);
        }
    }

    return 0;
}

// Function to count number of words in input string
int count_words(char *input)
{
    int count = 0;
    char delim[] = " \t\n"; // Delimiters are spaces, tabs, and newlines

    // Tokenize input string
    char *token = strtok(input, delim);
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, delim);
    }

    return count;
}

// Function to split input into separate words
void tokenize_input(char *input, char *words[])
{
    char delim[] = " \t\n"; // Delimiters are spaces, tabs, and newlines
    int i = 0;

    // Tokenize input string
    char *token = strtok(input, delim);
    while (token != NULL)
    {
        words[i++] = token;
        token = strtok(NULL, delim);
    }
}

// Function to summarize text
void summarize_text(char *input, char *output[], int num_sentences, int num_words)
{
    int num_input_words = count_words(input); // Number of words in input text
    int num_summary_words = num_sentences * num_words; // Total number of words to include in summary
    int num_output_sentences = 0; // Number of sentences included in output summary

    // If there are fewer input words than the requested number of summary words, use all input words
    if (num_input_words < num_summary_words)
    {
        num_summary_words = num_input_words;
    }

    // Split input text into separate words
    char *words[num_input_words];
    tokenize_input(input, words);

    // Copy first num_words into first summary sentence
    char sentence[MAX_INPUT_SIZE] = "";
    for (int i = 0; i < num_words; i++)
    {
        strcat(sentence, words[i]);
        strcat(sentence, " ");
    }
    output[num_output_sentences++] = strdup(sentence);

    // Copy remaining num_words into subsequent summary sentences
    for (int i = num_words; i < num_summary_words; i += num_words)
    {
        sentence[0] = '\0'; // Clear previous sentence

        // Copy num_words into sentence
        for (int j = i; j < i + num_words && j < num_input_words; j++)
        {
            strcat(sentence, words[j]);
            strcat(sentence, " ");
        }

        // Add sentence to output summary
        output[num_output_sentences++] = strdup(sentence);
    }
}