//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }
  
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,          // Deletion
                          d[i][j - 1] + 1,          // Insertion
                          d[i - 1][j - 1] + cost);  // Substitution
        }
    }

    int distance = d[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void interactive_mode() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance: %d\n", distance);
}

void batch_mode(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char str1[100], str2[100];
    
    while (fgets(str1, sizeof(str1), file) != NULL) {
        str1[strcspn(str1, "\n")] = 0; // Remove newline character
        if (fgets(str2, sizeof(str2), file) != NULL) {
            str2[strcspn(str2, "\n")] = 0; // Remove newline character
            int distance = levenshtein_distance(str1, str2);
            printf("Levenshtein Distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);
        }
    }

    fclose(file);
}

void show_menu() {
    printf("Levenshtein Distance Calculator\n");
    printf("1. Interactive Mode\n");
    printf("2. Batch Mode (from file)\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main(int argc, char *argv[]) {
    while (1) {
        show_menu();
        int option;
        scanf("%d", &option);
        getchar(); // Consume newline character
        switch (option) {
            case 1:
                interactive_mode();
                break;
            case 2:
                {
                    char file_path[100];
                    printf("Enter filename for batch processing: ");
                    fgets(file_path, sizeof(file_path), stdin);
                    file_path[strcspn(file_path, "\n")] = 0; // Remove newline character
                    batch_mode(file_path);
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}