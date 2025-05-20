//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length of a word
#define MAX_WORDS 1000 // Maximum number of words in a resume

// Resume structure
typedef struct resume {
    char* words[MAX_WORDS]; // Array of words in the resume
    int num_words; // Number of words in the resume
} Resume;

/**
 * Loads a resume from a file.
 * @param filename The name of the file to load the resume from.
 * @return The loaded resume.
 */
Resume* load_resume(char* filename) {
    Resume* resume = (Resume*) malloc(sizeof(Resume)); // Allocate memory for the resume
    resume->num_words = 0; // Initialize the number of words to 0

    FILE* file = fopen(filename, "r"); // Open the file for reading
    if (file != NULL) {
        char word[MAX_LEN]; // Buffer for reading in words

        // Read in each word from the file and add it to the resume
        while (fscanf(file, "%s", word) != EOF) {
            resume->words[resume->num_words] = strdup(word); // Add the word to the resume
            resume->num_words++; // Increment the number of words
        }

        fclose(file); // Close the file
    } else {
        printf("Error: could not open file %s\n", filename);
    }

    return resume;
}

/**
 * Frees the memory used by a resume.
 * @param resume The resume to free.
 */
void free_resume(Resume* resume) {
    // Free each word in the resume
    for (int i = 0; i < resume->num_words; i++) {
        free(resume->words[i]);
    }

    free(resume); // Free the resume itself
}

/**
 * Checks if a word is in a given list of keywords.
 * @param word The word to check.
 * @param keywords The array of keywords to check against.
 * @param num_keywords The number of keywords in the array.
 * @return 1 if the word is in the list of keywords, 0 otherwise.
 */
int is_keyword(char* word, char** keywords, int num_keywords) {
    // Check if the word is in the list of keywords
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

/**
 * Parses a resume and extracts information based on a set of keywords.
 * @param resume The resume to parse.
 * @param keywords The array of keywords to search for.
 * @param num_keywords The number of keywords in the array.
 */
void parse_resume(Resume* resume, char** keywords, int num_keywords) {
    // Initialize counters for each keyword
    int keyword_counts[num_keywords];
    for (int i = 0; i < num_keywords; i++) {
        keyword_counts[i] = 0;
    }

    // Iterate through each word in the resume
    for (int i = 0; i < resume->num_words; i++) {
        char* word = resume->words[i];

        // Check if the word is a keyword
        if (is_keyword(word, keywords, num_keywords)) {
            // Increment the counter for the keyword
            for (int j = 0; j < num_keywords; j++) {
                if (strcmp(word, keywords[j]) == 0) {
                    keyword_counts[j]++;
                    break;
                }
            }
        }
    }

    // Print out the keyword counts
    for (int i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i], keyword_counts[i]);
    }
}

int main() {
    // Load the resume from a file
    char* filename = "resume.txt";
    Resume* resume = load_resume(filename);

    // Define the keywords to search for
    char* keywords[] = {"C", "Java", "Python", "SQL", "JavaScript", "HTML", "CSS", "React", "Node.js", "MongoDB"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    // Parse the resume and extract information based on the keywords
    parse_resume(resume, keywords, num_keywords);

    // Free the memory used by the resume
    free_resume(resume);

    return 0;
}