//FormAI DATASET v1.0 Category: QR code generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_CODE_SIZE 21 // The size of the QR code matrix

/* Function prototypes */
void generate_qr_code(int matrix[QR_CODE_SIZE][QR_CODE_SIZE], char data[]);
void print_qr_code(int matrix[QR_CODE_SIZE][QR_CODE_SIZE]);

int main()
{
    char data[100]; // Input data
    int qr_code[QR_CODE_SIZE][QR_CODE_SIZE]; // QR code matrix

    // Read input data
    printf("Enter data: ");
    scanf("%s", data);

    // Generate QR code
    generate_qr_code(qr_code, data);

    // Print QR code
    print_qr_code(qr_code);

    return 0;
}

void generate_qr_code(int matrix[QR_CODE_SIZE][QR_CODE_SIZE], char data[])
{
    int i, j;
    int current_bit = 0; // Current bit position in the input data
    int data_length = strlen(data); // Length of input data
    int total_bits = data_length * 8; // Total number of bits in the input data
    int bit_array[total_bits]; // Array to store bits of input data

    // Convert input data to bit array
    for (i = 0; i < data_length; i++)
    {
        int num = (int) data[i];
        for (j = 7; j >= 0; j--)
        {
            bit_array[current_bit++] = (num >> j) & 1;
        }
    }

    // Initialize QR code matrix to 0
    for (i = 0; i < QR_CODE_SIZE; i++)
    {
        for (j = 0; j < QR_CODE_SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Add timing patterns
    for (i = 0; i < QR_CODE_SIZE; i++)
    {
        matrix[6][i] = (i % 2 == 0) ? 1 : 0;
        matrix[i][6] = (i % 2 == 0) ? 1 : 0;
    }

    // Add dark module
    matrix[8][QR_CODE_SIZE - 8] = 1;

    // Add format information
    int format_bits[] = {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1}; // Use default format bits for L (error correction level) = 01 (Low)
    for (i = 0; i < 13; i++)
    {
        matrix[(i < 6) ? i : (i + 1)][8] = format_bits[i];
        matrix[8][(i < 6) ? (8 - i) : (7 - i)] = format_bits[i];
    }

    // Add version information (if required)
    if (QR_CODE_SIZE >= 45)
    {
        int version_bits[] = {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0}; // Use default version bits for version 7
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 3; j++)
            {
                matrix[(QR_CODE_SIZE - 11) + j][(QR_CODE_SIZE - 9) + i] = version_bits[(i * 3) + j];
            }
        }
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 3; j++)
            {
                matrix[(QR_CODE_SIZE - 9) + i][(QR_CODE_SIZE - 11) + j] = version_bits[(i * 3) + j];
            }
        }
    }

    // Add data to matrix
    int row = QR_CODE_SIZE - 1;
    int col = QR_CODE_SIZE - 1;
    int current_direction = 0; // 0 = up, 1 = down
    while (current_bit < total_bits)
    {
        // Check if current bit position is within the first column
        if (col == 0)
        {
            // Flip current direction if necessary
            current_direction = (current_direction == 0) ? 1 : 0;
            // Move to next column
            col = 1;
        }
        // Check if current bit position is within the timing patterns
        else if ((row == 6) || (col == 6))
        {
            // Move to next column in the same direction
            if (current_direction == 0)
            {
                row--;
            }
            else
            {
                row++;
            }
        }
        // Check if current bit position is at the dark module
        else if ((row == 8) && (col == QR_CODE_SIZE - 8))
        {
            // Move to next row in the opposite direction
            if (current_direction == 0)
            {
                row++;
            }
            else
            {
                row--;
            }
        }
        // Check if current bit position is within the format information
        else if ((row >= 0 && row <= 8) && (col >= 0 && col <= 8))
        {
            // Move to next column in the same direction
            if (current_direction == 0)
            {
                row--;
            }
            else
            {
                row++;
            }
        }
        // Check if current bit position is within the version information (if present)
        else if ((QR_CODE_SIZE >= 45) && (row >= QR_CODE_SIZE - 11) && (col >= 0 && col <= 5))
        {
            // Move to next column in the same direction
            if (current_direction == 0)
            {
                row--;
            }
            else
            {
                row++;
            }
        }
        // Move to next row and/or column in the current direction
        else
        {
            if (current_direction == 0)
            {
                row--;
                col--;
            }
            else
            {
                row++;
                col--;
            }
        }
        // Add current bit to matrix
        matrix[row][col] = bit_array[current_bit++];
    }
}

void print_qr_code(int matrix[QR_CODE_SIZE][QR_CODE_SIZE])
{
    int i, j;

    // Print QR code matrix
    for (i = 0; i < QR_CODE_SIZE; i++)
    {
        for (j = 0; j < QR_CODE_SIZE; j++)
        {
            printf("%c ", (matrix[i][j] == 1) ? '#' : ' ');
        }
        printf("\n");
    }
}