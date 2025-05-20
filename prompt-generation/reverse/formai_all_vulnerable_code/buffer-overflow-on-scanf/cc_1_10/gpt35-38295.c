//FormAI DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char in_file[100], out_file[100], ch, key;
    int fib[100], i, n;

    printf("Enter the name of file to encrypt: ");
    scanf("%s", in_file);

    fp1 = fopen(in_file, "r");

    if(fp1 == NULL) {
        printf("Error: Could not open file %s.\n", in_file);
        exit(1);
    }

    printf("Enter the name of encrypted output file: ");
    scanf("%s", out_file);

    fp2 = fopen(out_file, "w");

    if(fp2 == NULL) {
        printf("Error: Could not open file %s.\n", out_file);
        exit(1);
    }
    
    // Creating the Fibonacci sequence array
    fib[0] = 1;
    fib[1] = 1;

    printf("Enter the number of terms in Fibonacci sequence used for encryption (at least 5): ");
    scanf("%d", &n);

    if (n < 5) {
        printf("Error: The number of Fibonacci sequence terms should be at least 5.\n");
        exit(1);
    }

    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Encryption process
    i = 0;

    while ((ch = fgetc(fp1)) != EOF) {
        key = (char) fib[i % n];
        ch = ch ^ key;
        fputc(ch, fp2);
        i++;
    }

    fclose(fp1);
    fclose(fp2);

    printf("The file %s has been successfully encrypted to %s.\n", in_file, out_file);

    return 0;
}