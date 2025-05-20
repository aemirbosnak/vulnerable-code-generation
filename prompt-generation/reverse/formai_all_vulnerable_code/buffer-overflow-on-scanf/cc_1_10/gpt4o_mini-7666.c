//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_WORD_LENGTH 100

void process_file(const char *filename);
void analyze_text(const char *text);
void print_statistics(int word_count, int line_count, int char_count, const char *longest_word, int exclamatory_count);

int main() {
    char filename[BUFFER_SIZE];

    printf("🚨 O-M-G! Welcome to the Shocking Text Processor! 🚨\n");
    printf("Please enter the filename to process (make sure it exists!): ");
    scanf("%s", filename);

    process_file(filename);
    
    return 0;
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "😱 Oh No! Could not open the file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char text[BUFFER_SIZE];
    char longest_word[MAX_WORD_LENGTH] = "";
    int word_count = 0, line_count = 0, char_count = 0, exclamatory_count = 0;

    printf("🔍 Analyzing the file... Hold onto your hat!\n");

    while (fgets(text, sizeof(text), file) != NULL) {
        line_count++;

        // Count characters
        char_count += strlen(text);

        // Analyze each line for words and exclamations
        char *token = strtok(text, " \n");
        while (token != NULL) {
            word_count++;
            if (strlen(token) > strlen(longest_word)) {
                strcpy(longest_word, token);
            }
            if (token[strlen(token) - 1] == '!') {
                exclamatory_count++;
            }
            token = strtok(NULL, " \n");
        }
    }

    fclose(file);
    printf("📊 Analysis complete! 🎉\n");
    print_statistics(word_count, line_count, char_count, longest_word, exclamatory_count);
}

void print_statistics(int word_count, int line_count, int char_count, const char *longest_word, int exclamatory_count) {
    printf("🔔 Total Lines: %d\n", line_count);
    printf("📝 Total Words: %d\n", word_count);
    printf("🔤 Total Characters: %d\n", char_count);
    printf("🏆 Longest Word: %s\n", longest_word);
    printf("❗ Total Exclamatory Sentences: %d\n", exclamatory_count);

    if (exclamatory_count > 0) {
        printf("🚀 Wow! Your text is full of excitement! ⚡\n");
    } else {
        printf("😐 Hmm... Needs more excitement, don’t you think? 💭\n");
    }
}