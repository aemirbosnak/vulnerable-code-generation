//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

struct word_freq_node
{
    char word[MAX_WORD_LEN+1];
    int freq;
    struct word_freq_node *left, *right;
};

void add_word_to_freq(struct word_freq_node **root, char *word)
{
    if (*root == NULL)
    {
        (*root) = (struct word_freq_node*)malloc(sizeof(struct word_freq_node));
        strcpy((*root)->word, word);
        (*root)->freq = 1;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (strcmp((*root)->word, word) == 0)
    {
        (*root)->freq++;
    }
    else if (strcmp((*root)->word, word) > 0)
    {
        add_word_to_freq(&((*root)->left), word);
    }
    else
    {
        add_word_to_freq(&((*root)->right), word);
    }
}

void print_word_freq(struct word_freq_node *root)
{
    if (root)
    {
        print_word_freq(root->left);
        printf("%s: %d\n", root->word, root->freq);
        print_word_freq(root->right);
    }
}

int main()
{
    char filename[50];
    printf("Enter the name of the file to be read:\n");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (!file)
    {
        printf("Error in opening file\n");
        return 0;
    }

    struct word_freq_node *root = NULL;

    char line[1000];
    while (fgets(line, sizeof(line), file))
    {
        char *word = strtok(line, " ,.!?:;\n");

        while (word != NULL)
        {
            for (int i=0; i<strlen(word); i++)
            {
                word[i] = tolower(word[i]);
            }
            add_word_to_freq(&root, word);
            word = strtok(NULL, " ,.!?:;\n");
        }
    }

    fclose(file);

    print_word_freq(root);

    return 0;
}