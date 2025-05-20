//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_CONTENT_LENGTH 1000
#define DEFAULT_TEST_CONTENT "The quick brown fox jumps over the lazy dog."

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a sentence to type.\n");
    printf("Try to type it as quickly and accurately as possible.\n");
    printf("Press enter after typing the text to get your results.\n");
}

char* getTestContent() {
    char *content = (char *)malloc(MAX_CONTENT_LENGTH * sizeof(char));
    if (content == NULL) {
        fprintf(stderr, "Failed to allocate memory for content.\n");
        exit(EXIT_FAILURE);
    }
    
    // Get custom content
    printf("Enter a sentence for the typing test (or press enter for default):\n");
    fgets(content, MAX_CONTENT_LENGTH, stdin);
    
    // Remove newline character
    content[strcspn(content, "\n")] = 0;
    
    // If input is empty, use default content
    if (strlen(content) == 0) {
        strcpy(content, DEFAULT_TEST_CONTENT);
    }
    
    return content;
}

double calculateSpeed(double timeTaken, const char* typedContent) {
    int wordCount = 0;
    const char *ptr = typedContent;

    while (1) {
        while (*ptr == ' ' && *ptr != '\0') {
            ptr++;
        }
        if (*ptr == '\0') {
            break;
        }
        wordCount++;

        while (*ptr != ' ' && *ptr != '\0') {
            ptr++;
        }
    }

    return (wordCount / timeTaken) * 60; // words per minute
}

void startTypingTest(const char* testContent) {
    char typedContent[MAX_CONTENT_LENGTH];
    clock_t startTime, endTime;

    printf("\nYour typing test content:\n");
    printf("\"%s\"\n", testContent);
    
    displayInstructions();
    
    printf("Start typing now...\n");
    startTime = clock();
    fgets(typedContent, MAX_CONTENT_LENGTH, stdin);
    endTime = clock();

    // Remove newline character
    typedContent[strcspn(typedContent, "\n")] = 0;

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC; // in seconds
    double speed = calculateSpeed(timeTaken, typedContent);

    printf("You took %.2f seconds to type.\n", timeTaken);
    printf("Your typing speed is %.2f words per minute.\n", speed);
    
    if (strcmp(typedContent, testContent) == 0) {
        printf("Great job! You typed it correctly!\n");
    } else {
        printf("You made some mistakes.\n");
    }
}

int main() {
    char *testContent;

    testContent = getTestContent();
    startTypingTest(testContent);

    free(testContent);
    return 0;
}