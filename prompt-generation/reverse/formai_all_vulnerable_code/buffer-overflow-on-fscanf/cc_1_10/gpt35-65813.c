//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_banner() {
    printf("**************************************************\n");
    printf("*****    SHAPE-SHIFTING C WORD COUNT TOOL    *****\n");
    printf("**************************************************\n\n");
}

int main(int argc, char *argv[]) {
    char *shape[4] = {"square", "circle", "triangle", "star"};
    int size = sizeof(shape)/sizeof(shape[0]);
    
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }
    
    char word[1024];
    int count = 0, i, j, k;
    
    while (fscanf(fp, "%s", word) == 1) {
        for (i = 0; i < strlen(word); i++)
            word[i] = tolower(word[i]);
        if (strcmp(word, "c") == 0)
            count++;
    }
    
    printf("Total occurrences of 'c' in program: %d\n", count);
    
    srand(time(0));
    int current_shape = rand() % size;
    
    if (strcmp(argv[1], "main.c") == 0) {
        print_banner();
        printf("Current shape: %s\n", shape[current_shape]);
        printf("\n");
        
        if (strcmp(shape[current_shape], "square") == 0) {
            printf("* * * * *\n");
            printf("*       *\n");
            printf("*       *\n");
            printf("*       *\n");
            printf("* * * * *\n");
        } else if (strcmp(shape[current_shape], "circle") == 0) {
            printf("   ***   \n");
            printf(" *     * \n");
            printf("*       *\n");
            printf(" *     * \n");
            printf("   ***   \n");
        } else if (strcmp(shape[current_shape], "triangle") == 0) {
            printf("    *    \n");
            printf("   * *   \n");
            printf("  *   *  \n");
            printf(" * * * * \n");
        } else if (strcmp(shape[current_shape], "star") == 0) {
            printf("    *    \n");
            printf("   **   \n");
            printf("  ***  \n");
            printf(" ***** \n");
            printf("*******\n");
            printf(" ***** \n");
            printf("  ***   \n");
            printf("   **   \n");
            printf("    *    \n");
        }
    }
    
    fclose(fp);
    
    return 0;
}