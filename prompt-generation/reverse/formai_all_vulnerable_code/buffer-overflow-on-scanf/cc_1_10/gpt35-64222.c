//FormAI DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50

int main()
{
    char word[MAX_LENGTH], dictionary[MAX_LENGTH];
    int len_word, len_dic, flag = 0;

    printf("Enter the word to be checked: ");
    scanf("%s", word);
    len_word = strlen(word);

    FILE* fp = fopen("dictionary.txt", "r"); // Open the dictionary file

    if (fp == NULL) // checking whether the dictionary file is present or not
    {
        printf("Unable to open dictionary file.\n");
        return 0;
    }

    while (fgets(dictionary, MAX_LENGTH, fp))
    {
        len_dic = strlen(dictionary);

        if(len_dic == len_word) // Checking if length of word matches with length of the dictionary words
        {
            for(int i=0; i<len_dic; i++)
            {
                if(word[i] != dictionary[i])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag==0) // If the word is found in the dictionary, set the flag to 0 and break the loop
            {
                printf("The word \"%s\" is spelled correctly.\n", word);
                fclose(fp);
                return 0;
            }
            else // If the word is not found in the dictionary, set the flag to 1 and continue the loop
            {
                flag = 0;
            }
        }
    }
    // If the word is not found in the dictionary, print the error message
    printf("The word \"%s\" is spelled incorrectly.\n", word);
    fclose(fp);
    return 0;
}