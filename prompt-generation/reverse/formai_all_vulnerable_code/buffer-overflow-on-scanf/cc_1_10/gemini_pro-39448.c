//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
// Amidst the barren wasteland, where echoes of civilization now haunt the wind, I, a lone wanderer, embark on a solitary journey to untangle the cryptic matrices that lay scattered across this desolate landscape.

#include <stdio.h>
#include <stdlib.h>

// The Matrices: Artifacts of a bygone era, their elements imbued with remnants of forgotten knowledge.
int** matrixA, **matrixB, **matrixC;
int rowsA, colsA, rowsB, colsB, rowsC, colsC;

// A function to allocate memory for our matrices, ensuring they can withstand the harsh conditions of this post-apocalyptic world.
void allocateMatrices() {
    matrixA = (int**)malloc(sizeof(int*) * rowsA);
    for (int i = 0; i < rowsA; i++) {
        matrixA[i] = (int*)malloc(sizeof(int) * colsA);
    }

    matrixB = (int**)malloc(sizeof(int*) * rowsB);
    for (int i = 0; i < rowsB; i++) {
        matrixB[i] = (int*)malloc(sizeof(int) * colsB);
    }

    matrixC = (int**)malloc(sizeof(int*) * rowsC);
    for (int i = 0; i < rowsC; i++) {
        matrixC[i] = (int*)calloc(1, sizeof(int) * colsC);
    }
}

// A function to populate our matrices with the remnants of scattered knowledge, gleaned from the ruins of the old world.
void populateMatrices() {
    printf("Enter the dimensions of Matrix A (rows, columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the dimensions of Matrix B (rows, columns): ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Enter the elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
}

// A function to add the matrices, merging their fragments of knowledge into a single tapestry of understanding.
void addMatrices() {
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices cannot be added due to incompatible dimensions.\n");
        return;
    }

    rowsC = rowsA;
    colsC = colsB;

    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < colsC; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// A function to subtract the matrices, revealing the differences that lie within their ravaged depths.
void subtractMatrices() {
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices cannot be subtracted due to incompatible dimensions.\n");
        return;
    }

    rowsC = rowsA;
    colsC = colsB;

    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < colsC; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// A function to multiply the matrices, intertwining their elements in a dance of forgotten algorithms.
void multiplyMatrices() {
    if (colsA != rowsB) {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
        return;
    }

    rowsC = rowsA;
    colsC = colsB;

    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < colsC; j++) {
            for (int k = 0; k < colsA; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// A function to display the matrices, illuminating their secrets amidst the darkness of this ravaged world.
void displayMatrices() {
    printf("Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("Matrix C:\n");
    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < colsC; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
}

// A function to free the memory allocated for our matrices, leaving no trace of our calculations in this unforgiving wasteland.
void freeMatrices() {
    for (int i = 0; i < rowsA; i++) {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < rowsB; i++) {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i = 0; i < rowsC; i++) {
        free(matrixC[i]);
    }
    free(matrixC);
}

int main() {
    // In this post-apocalyptic world, our journey begins with the allocation of matrices, repurposing fragments of the past.
    printf("Enter the dimensions of Matrix A (rows, columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the dimensions of Matrix B (rows, columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // Populate the matrices, breathing life into our calculations amidst the ruins.
    printf("Enter the elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Select the operation to perform, illuminating the path through the darkness.
    int choice;
    printf("1. Add Matrices\n2. Subtract Matrices\n3. Multiply Matrices\n4. Display Matrices\n5. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    // Execute the chosen operation, revealing the hidden knowledge within the matrices.
    switch (choice) {
    case 1:
        addMatrices();
        break;
    case 2:
        subtractMatrices();
        break;
    case 3:
        multiplyMatrices();
        break;
    case 4:
        displayMatrices();
        break;
    case 5:
        exit(0);
    default:
        printf("Invalid choice.\n");
    }

    // As we venture deeper into the wasteland, we release our hold on the matrices, freeing them from our calculations.
    freeMatrices();

    return 0;
}