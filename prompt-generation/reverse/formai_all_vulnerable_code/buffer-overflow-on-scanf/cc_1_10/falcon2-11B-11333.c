//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <crypt.h>

// Function to generate a secure password
char* generate_password(int num_words, char* words[]) {
    char* password = (char*)malloc(sizeof(char) * (num_words + 8));
    int i;
    int j;
    for (i = 0; i < num_words; i++) {
        password[i] = words[i][0];
    }
    for (i = 0; i < 8; i++) {
        password[num_words] = (char)(((unsigned int)password[num_words - 1] + 1) % 26 + 'a');
    }
    for (i = num_words + 1; i < num_words + 8; i++) {
        password[i] = (char)(((unsigned int)password[i - 1] + 1) % 26 + 'a');
    }
    for (i = 0; i < 8; i++) {
        password[i + num_words] = (char)(((unsigned int)password[i] + 1) % 26 + 'a');
    }
    for (i = 0; i < num_words; i++) {
        password[i + num_words + 8] = words[i][0];
    }
    for (i = 0; i < 8; i++) {
        password[i + num_words + 16] = (char)(((unsigned int)password[i + num_words + 8] + 1) % 26 + 'a');
    }
    for (i = 0; i < num_words; i++) {
        password[i + num_words + 24] = words[i][0];
    }
    return password;
}

int main() {
    char* words[5];
    int num_words;
    printf("Enter the number of words you would like to use in the password: ");
    scanf("%d", &num_words);
    printf("Enter the words you would like to use in the password: ");
    for (int i = 0; i < num_words; i++) {
        fgets(words[i], sizeof(words[i]), stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
    }
    char* password = generate_password(num_words, words);
    printf("Your secure password is: %s\n", password);
    free(password);
    return 0;
}