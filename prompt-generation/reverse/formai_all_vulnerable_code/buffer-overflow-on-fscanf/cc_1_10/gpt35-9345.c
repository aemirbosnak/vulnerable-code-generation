//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
//This program is a spell-checker that reads in a text file, compares each word in the file to a dictionary of known words, and outputs all misspelled words in the text file.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//define the maximum length of a word and the maximum number of words in the dictionary
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

//function to check if a word is in the dictionary
int spell_check(char *word, char dictionary[MAX_NUM_WORDS][MAX_WORD_LENGTH], int num_words)
{
    int i;

    //convert word to lowercase
    for(i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]);

    //compare word to each word in the dictionary
    for(i = 0; i < num_words; i++)
    {
        if(strcmp(word, dictionary[i]) == 0)
            return 1;
    }

    //if word is not found in the dictionary, return 0
    return 0;
}

int main(int argc, char **argv)
{
    char *filename = argv[1]; //get filename from command line argument
    FILE *file = fopen(filename, "r"); //open file for reading

    char dictionary[MAX_NUM_WORDS][MAX_WORD_LENGTH]; //array to store words in dictionary
    int num_words = 0; //number of words in dictionary

    //read words from dictionary file into array
    char dict_filename[] = "dictionary.txt";
    FILE *dict_file = fopen(dict_filename, "r");
    char dict_word[MAX_WORD_LENGTH];
    while(fscanf(dict_file, "%s", dict_word) == 1)
    {
        strcpy(dictionary[num_words], dict_word);
        num_words++;
    }

    //check each word in input file for spelling errors
    char input_word[MAX_WORD_LENGTH];
    while(fscanf(file, "%s", input_word) == 1)
    {
        if(!spell_check(input_word, dictionary, num_words))
            printf("%s is misspelled\n", input_word);
    }

    //close files
    fclose(file);
    fclose(dict_file);

    return 0;

}