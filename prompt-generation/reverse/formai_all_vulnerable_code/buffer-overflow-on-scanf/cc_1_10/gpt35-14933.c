//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

enum alien_chars { A = 1, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };

const char* alien_alphabet[] = { "?", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

char* translate_to_english(char*);
char* translate_to_alien(char*);

int main() {
    int choice = 0;
    
    do {
        printf("\n1. Translate message to Alien Language\n2. Translate message to English\n0. Exit\n\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("\nExiting translator...\n");
                break;
            case 1: {
                char message[100];
                printf("\nEnter message to translate to Alien Language (only alphabet characters accepted): ");
                scanf("%s", message);
                char* translated = translate_to_alien(message);
                printf("\nTranslated message: %s\n", translated);
                break;
            }
            case 2: {
                char message[100];
                printf("\nEnter message to translate to English (only numbered characters accepted): ");
                scanf("%s", message);
                char* translated = translate_to_english(message);
                printf("\nTranslated message: %s\n", translated);
                break;
            }
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 0);
    
    return 0;
}

char* translate_to_english(char* alien_message) {
    int len = strlen(alien_message);
    char english_message[100];
    
    for (int i = 0; i < len; i++) {
        char temp[2];
        sprintf(temp, "%c", alien_message[i]);
        
        for (int j = 1; j <= 26; j++) {
            if (strcmp(temp, alien_alphabet[j]) == 0) {
                sprintf(temp, "%d", j);
                break;
            }
        }
        strcat(english_message, temp);
    }
    
    return english_message;
}

char* translate_to_alien(char* english_message) {
    int len = strlen(english_message);
    char alien_message[100];
    
    for (int i = 0; i < len;) {
        int num = 0;
        
        if (english_message[i] >= '0' && english_message[i] <= '9') {
            num = english_message[i] - '0';
            i++;
            
            if (english_message[i] >= '0' && english_message[i] <= '9') {
                num = num * 10 + (english_message[i] - '0');
                i++;
            }
            char temp[2];
            sprintf(temp, "%s", alien_alphabet[num]);
            strcat(alien_message, temp);
        }
        else {
            i++;
        }
    }
    
    return alien_message;
}