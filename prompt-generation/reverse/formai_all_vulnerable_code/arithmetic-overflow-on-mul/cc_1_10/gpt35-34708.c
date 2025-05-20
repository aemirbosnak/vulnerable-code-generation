//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define DICTIONARY_SIZE 20

// dictionary of Alien words and their translations
char alienDictionary[DICTIONARY_SIZE][2][MAX_WORD_LENGTH] = {
    {"blorg", "hello"},
    {"skizz", "goodbye"},
    {"plip", "yes"},
    {"froon", "no"},
    {"grump", "sorry"},
    {"chack", "thanks"},
    {"krill", "please"},
    {"snorf", "sorry"},
    {"blix", "love"},
    {"jorb", "friend"},
    {"glooz", "heart"},
    {"flotz", "home"},
    {"plorg", "food"},
    {"klimp", "water"},
    {"mikl", "fire"},
    {"vloot", "sky"},
    {"hloob", "moon"},
    {"jim", "sun"},
    {"qlib", "earth"},
    {"zlorf", "universe"},
};

// function to convert an alien word to its translation
void translateWord(char* alienWord, char* translation) {
    for(int i = 0; i < DICTIONARY_SIZE; i++) {
        if(strcmp(alienWord, alienDictionary[i][0]) == 0) {
            strcpy(translation, alienDictionary[i][1]);
            return;
        }
    }
    strcpy(translation, "Unknown word");
}

// async function to process incoming messages and translate them
void translateMessages(char** messages, int numMessages, char* translatedMessages[]) {
    for(int i = 0; i < numMessages; i++) {
        // simulate some processing time
        int delay = rand() % 2000 + 1000;
        struct timespec t;
        t.tv_sec = 0;
        t.tv_nsec = delay * 1000000;
        nanosleep(&t, NULL);
        
        // translate the current message
        char* currentMessage = messages[i];
        char* currentTranslation = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
        char* token = strtok(currentMessage, " ");
        while(token != NULL) {
            char* currentWord = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
            strcpy(currentWord, token);
            translateWord(currentWord, currentTranslation);
            strcat(currentTranslation, " ");
            strcat(currentTranslation, currentWord);
            token = strtok(NULL, " ");
        }
        translatedMessages[i] = currentTranslation;
    }
}

// helper function to print an array of strings
void printArray(char** array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }
}

int main() {
    // define some messages to be translated
    char* messages[5] = {
        "blorg jorb froon glooz",
        "skizz qlib flotz hloob plorg",
        "mikl blix vloot plip chack krill snorf",
        "jim zlorf",
        "foo bar baz"
    };
    int numMessages = sizeof(messages) / sizeof(char*);
    
    // seed the random function with the current time
    srand(time(NULL));
    
    // asynchronous translation of messages
    char* translatedMessages[5];
    translateMessages(messages, numMessages, translatedMessages);
    
    // print the translated messages
    printf("Original Messages:\n");
    printArray(messages, numMessages);
    printf("Translated Messages:\n");
    printArray(translatedMessages, numMessages);
    
    // free up memory allocated for translated messages
    for(int i = 0; i < numMessages; i++) {
        free(translatedMessages[i]);
    }
    
    return 0;
}