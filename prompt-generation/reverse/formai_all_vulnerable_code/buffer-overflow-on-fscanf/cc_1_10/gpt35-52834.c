//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include<stdio.h>
#include<string.h>
#define MAX 1000

char dict[MAX][MAX], doc[MAX][MAX];

void read_dictionary();
void read_document();
void check_spelling();

int main() {
    read_dictionary();
    read_document();
    check_spelling();
    return 0;
}

void read_dictionary() {
    FILE *file = fopen("dictionary.txt", "r");
    char word[MAX];
    int idx = 0;
    while(fscanf(file, "%s", word) != EOF) {
        strcpy(dict[idx], word);
        idx++;
    }
    fclose(file);
}

void read_document() {
    FILE *file = fopen("document.txt", "r");
    char word[MAX];
    int idx = 0;
    while(fscanf(file, "%s", word) != EOF) {
        strcpy(doc[idx], word);
        idx++;
    }
    fclose(file);
}

void check_spelling() {
    printf("Misspelled words:\n");
    for(int i=0; i<MAX && doc[i][0]!='\0'; i++) {
        int found = 0;
        for(int j=0; j<MAX && dict[j][0]!='\0'; j++) {
            if(strcmp(doc[i], dict[j]) == 0) {
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("%s\n", doc[i]);
        }
    }
}