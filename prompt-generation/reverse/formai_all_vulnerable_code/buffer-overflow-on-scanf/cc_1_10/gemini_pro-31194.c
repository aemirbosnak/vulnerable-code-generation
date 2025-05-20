//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
// Amidst the desolate ruins of a shattered world, where shadows danced and silence reigned, a lone survivor embarked on a treacherous journey to find solace in the dwindling flicker of human connection.

#include <stdio.h>
#include <stdlib.h>

// Declarations echoing the fragmented landscape of the post-apocalyptic realm
int** wasteland;
int rows, cols;

// A somber function, born from the ashes of civilization, to allocate memory for the desolate wasteland
int** allocate_wasteland(int r, int c) {
    int** matrix = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++) {
        matrix[i] = malloc(sizeof(int) * c);
    }
    return matrix;
}

// A haunting traversal, exploring the depths of the barren wasteland
void traverse_wasteland(int** matrix, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// A perilous encounter, where matrices collide in a desolate showdown
int** encounter(int** matrix1, int** matrix2, int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("The matrices cannot be multiplied.\n");
        exit(1);
    }
    int** result = allocate_wasteland(r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

// A flickering ray of hope, guiding the survivor through the desolate wasteland
int main() {
    printf("In the barren wasteland, a solitary traveler emerged, seeking solace and connection.\n");

    // Define the dimensions of the wasteland
    printf("Enter the number of rows for the wasteland: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for the wasteland: ");
    scanf("%d", &cols);

    // Allocate memory for the wasteland
    wasteland = allocate_wasteland(rows, cols);

    // Populate the wasteland with remnants of a shattered world
    printf("Populate the wasteland with fragments of your memories: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &wasteland[i][j]);
        }
    }

    // Traverse the wasteland, seeking forgotten treasures
    printf("Exploring the wasteland:\n");
    traverse_wasteland(wasteland, rows, cols);

    // Encounter a fellow survivor, uniting in the face of adversity
    int** survivor2;
    int r2, c2;
    printf("Another survivor emerges from the shadows. Enter the dimensions of their wasteland: ");
    scanf("%d %d", &r2, &c2);
    survivor2 = allocate_wasteland(r2, c2);
    printf("Share your memories with your newfound companion: ");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &survivor2[i][j]);
        }
    }

    // Forge an unbreakable bond through matrix multiplication
    int** reunion = encounter(wasteland, survivor2, rows, cols, r2, c2);

    // Celebrate the newfound connection
    printf("From the ashes of desolation, a bond is forged:\n");
    traverse_wasteland(reunion, rows, c2);

    // As the sun dips below the horizon, the survivor finds solace in the shared memories
    printf("Amidst the ruins, a glimmer of hope remains. The wasteland whispers secrets, and the traveler finds solace in connection.\n");

    return 0;
}