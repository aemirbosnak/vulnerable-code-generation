//FormAI DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
/* 
* Romeo and Juliet: A Matrix Operations Example
* By Chatbot
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int nrows;
    int ncols;
    double* data;
} matrix;

matrix createMatrix (int nrows, int ncols) {
    matrix mat;
    mat.nrows = nrows;
    mat.ncols = ncols;
    mat.data = (double*) malloc (nrows * ncols * sizeof (double));
    return mat;
}

void freeMatrix (matrix mat) {
    free (mat.data);
}

void printMatrix (matrix mat) {
    int i, j;
    for (i = 0; i < mat.nrows; i++) {
        for (j = 0; j < mat.ncols; j++) {
            printf ("%f\t", mat.data[i * mat.ncols + j]);
        }
        printf ("\n");
    }
}

matrix addMatrices (matrix mat1, matrix mat2) {
    if (mat1.nrows != mat2.nrows || mat1.ncols != mat2.ncols) {
        printf ("Romeo: Oh, Juliet, our matrices are not compatible!\n");
        printf ("Juliet: Fear not, Romeo! I shall fix this.\n");
        return createMatrix (0, 0);
    }
    matrix result = createMatrix (mat1.nrows, mat1.ncols);
    int i, j;
    for (i = 0; i < mat1.nrows; i++) {
        for (j = 0; j < mat1.ncols; j++) {
            result.data[i * mat1.ncols + j] = mat1.data[i * mat1.ncols + j] + mat2.data[i * mat2.ncols + j];
        }
    }
    printf ("Romeo: My Juliet, here is our new matrix, born of love and addition!\n");
    return result;
}

matrix multiplyMatrices (matrix mat1, matrix mat2) {
    if (mat1.ncols != mat2.nrows) {
        printf ("Romeo: Oh, Juliet, our matrices are not compatible!\n");
        printf ("Juliet: Fear not, Romeo! I shall fix this.\n");
        return createMatrix (0, 0);
    }
    matrix result = createMatrix (mat1.nrows, mat2.ncols);
    int i, j, k;
    double sum;
    for (i = 0; i < mat1.nrows; i++) {
        for (j = 0; j < mat2.ncols; j++) {
            sum = 0;
            for (k = 0; k < mat1.ncols; k++) {
                sum += mat1.data[i * mat1.ncols + k] * mat2.data[k * mat2.ncols + j];
            }
            result.data[i * mat2.ncols + j] = sum;
        }
    }
    printf ("Romeo: My sweet Juliet, I have multiplied our matrices into a new creation!\n");
    return result;
}

int main () {
    matrix mat1, mat2, result;
    int nrows1, ncols1, nrows2, ncols2, choice;
    double* data1, * data2;
    
    /* Asking for input from the user */
    printf ("Romeo: My Juliet, let us create two matrices using our love!\n");
    printf ("How many rows do we want for our first matrix?\n");
    scanf ("%d", &nrows1);
    printf ("How many columns do we want for our first matrix?\n");
    scanf ("%d", &ncols1);
    data1 = (double*) malloc (nrows1 * ncols1 * sizeof (double));
    printf ("Now let us fill in the first matrix. Enter the values one by one:\n");
    int i;
    for (i = 0; i < nrows1 * ncols1; i++) {
        scanf ("%lf", &data1[i]);
    }
    mat1.nrows = nrows1;
    mat1.ncols = ncols1;
    mat1.data = data1;
    printf ("\n");
    
    printf ("How many rows do we want for our second matrix?\n");
    scanf ("%d", &nrows2);
    printf ("How many columns do we want for our second matrix?\n");
    scanf ("%d", &ncols2);
    data2 = (double*) malloc (nrows2 * ncols2 * sizeof (double));
    printf ("Now let us fill in the second matrix. Enter the values one by one:\n");
    for (i = 0; i < nrows2 * ncols2; i++) {
        scanf ("%lf", &data2[i]);
    }
    mat2.nrows = nrows2;
    mat2.ncols = ncols2;
    mat2.data = data2;
    printf ("\n");
    
    /* Asking the user what matrix operation to perform */
    printf ("Romeo: My dearest Juliet, what operation shall I perform on our matrices?\n");
    printf ("1. Add\n");
    printf ("2. Multiply\n");
    scanf ("%d", &choice);
    printf ("\n");
    
    /* Performing the matrix operation */
    switch (choice) {
        case 1:
            result = addMatrices (mat1, mat2);
            break;
        case 2:
            result = multiplyMatrices (mat1, mat2);
            break;
        default:
            printf ("Romeo: Oh, my fair Juliet, you have no idea how much you confuse me sometimes!\n");
            return -1;
            break;
    }
    
    /* Displaying the result */
    printMatrix (result);
    
    /* Freeing memory */
    freeMatrix (mat1);
    freeMatrix (mat2);
    freeMatrix (result);
    printf ("\nRomeo: Our love has created miracles today, my Juliet. Until next time!\n\n");
    return 0;
}