//FormAI DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char sentence[1000];
    int key = 7; //Key used for encryption
    int choice;
    int i;

    printf("Enter a sentence for encryption: ");
    fgets(sentence, 1000, stdin);
    sentence[strcspn(sentence, "\n")] = 0; //Remove newline character from the end of sentence

    printf("Please select an encryption algorithm:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    scanf("%d", &choice);

    //Caesar Cipher encryption
    if(choice == 1){
        char encrypted_sentence[strlen(sentence)];
        for(i = 0; i < strlen(sentence); i++){
            if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
                encrypted_sentence[i] = ((sentence[i] - 'A') + key) % 26 + 'A';
            }
            else if(sentence[i] >= 'a' && sentence[i] <= 'z'){
                encrypted_sentence[i] = ((sentence[i] - 'a') + key) % 26 + 'a';
            }
            else{
                encrypted_sentence[i] = sentence[i];
            }
        }
        printf("Encrypted message: %s\n", encrypted_sentence);
    }

    //Vigenere Cipher encryption
    else if(choice == 2){
        char keyword[100];
        printf("Enter a keyword for encryption: ");
        scanf("%s", keyword);

        char encrypted_sentence[strlen(sentence)];
        for(i = 0; i < strlen(sentence); i++){
            int j = i % strlen(keyword);
            if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
                encrypted_sentence[i] = ((sentence[i] - 'A') + (keyword[j] - 'a')) % 26 + 'A';
            }
            else if(sentence[i] >= 'a' && sentence[i] <= 'z'){
                encrypted_sentence[i] = ((sentence[i] - 'a') + (keyword[j] - 'a')) % 26 + 'a';
            }
            else{
                encrypted_sentence[i] = sentence[i];
            }
        }
        printf("Encrypted message: %s\n", encrypted_sentence);
    }

    //Invalid choice
    else{
        printf("Invalid choice. Please choose either 1 or 2.\n");
    }

    return 0;
}