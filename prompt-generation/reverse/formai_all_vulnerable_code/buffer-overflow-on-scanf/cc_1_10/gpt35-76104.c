//FormAI DATASET v1.0 Category: Spell checking ; Style: surrealist
#include<stdio.h>
#include<string.h>

// Declare the function to check spelling
void surreal_spell_check(char* word);

int main(){

    // Prompt user to enter a word
    printf("Welcome to the surreal spell checker.\n");
    printf("Please enter a word to check its spelling:\n");

    // Obtain the user input
    char input_word[50];
    scanf("%s",input_word);

    // Call the function to check spelling
    surreal_spell_check(input_word);

    return 0;
}

// Define the function to check spelling
void surreal_spell_check(char* word){

    // Initialize the surreal dictionary
    char surreal_dict[8][20] = {"plastic","rainbow","unicorn","jellyfish","butterfly",
                                "cosmic","mermaid","thunder"};

    // Declare a flag to indicate if the word is found in the dictionary
    int found_flag = 0;

    // Loop through the surreal dictionary to check if the word is found
    for(int i=0; i<8; i++){

        // Compare the user input word with a word from the dictionary
        if(strcmp(word,surreal_dict[i])==0){
            found_flag = 1;
            printf("The spelling of your word is correct in the surreal world.\n");
            printf("Congratulations on entering the world of the unimaginable!\n");
            break;
        }
    }

    // If the word is not found in the surreal dictionary, suggest possible alternatives
    if (found_flag==0){
        printf("Your word is not found in the surreal dictionary.\n");
        printf("Here are some suggestions:\n");

        // Initialize the list of potential alternatives
        char surreal_alts[5][20] = {"plastik","rainbowe","unicorne","jellyfishe","butterfy"};
        for(int i=0; i<5; i++){
            printf("%s\n", surreal_alts[i]);
        }
        printf("These may not be conventional spellings, but in the surreal world anything is possible!\n");
    }
}