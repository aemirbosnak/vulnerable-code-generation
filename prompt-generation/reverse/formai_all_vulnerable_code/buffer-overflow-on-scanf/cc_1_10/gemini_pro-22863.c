//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Player thread function
void *player_thread(void *arg) {
    char *text = (char *)arg;
    int len = strlen(text);

    // Convert text to Morse code
    char *morse_code = malloc(len * 5);
    int i, j, k = 0;
    for (i = 0; i < len; i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }
        for (j = 0; j < 26; j++) {
            if (ch == 'a' + j) {
                strcpy(morse_code + k, morse_table[j]);
                k += strlen(morse_table[j]);
                strcat(morse_code + k, " ");
                k++;
            }
        }
    }

    // Print Morse code
    printf("%s", morse_code);

    // Free memory
    free(morse_code);

    return NULL;
}

int main() {
    // Get input from players
    char player1_text[100], player2_text[100];
    printf("Player 1: ");
    scanf("%s", player1_text);
    printf("Player 2: ");
    scanf("%s", player2_text);

    // Create player threads
    pthread_t player1_thread, player2_thread;
    pthread_create(&player1_thread, NULL, player_thread, player1_text);
    pthread_create(&player2_thread, NULL, player_thread, player2_text);

    // Join player threads
    pthread_join(player1_thread, NULL);
    pthread_join(player2_thread, NULL);

    return 0;
}