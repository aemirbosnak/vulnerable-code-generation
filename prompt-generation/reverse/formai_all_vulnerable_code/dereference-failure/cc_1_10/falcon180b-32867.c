//Falcon-180B DATASET v1.0 Category: Encryption ; Style: automated
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000000

int main() {
    char input_file[MAX_SIZE], output_file[MAX_SIZE];
    FILE *in, *out;
    char ch;
    int key = 0, count = 0, temp = 0;
    char *message = (char *)malloc(MAX_SIZE * sizeof(char));

    printf("Enter the input file name: ");
    scanf("%s", input_file);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    in = fopen(input_file, "r");
    if (in == NULL) {
        printf("Error opening input file.\n");
        return 0;
    }

    while ((ch = fgetc(in))!= EOF) {
        message[count++] = ch;
    }

    fclose(in);

    printf("Enter the key: ");
    scanf("%d", &key);

    temp = key % 26;

    for (int i = 0; i < count; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] + temp);
            } else {
                message[i] = tolower(message[i] + temp);
            }
        } else {
            message[i] = message[i];
        }
    }

    out = fopen(output_file, "w");
    if (out == NULL) {
        printf("Error opening output file.\n");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fputc(message[i], out);
    }

    fclose(out);

    printf("File encrypted successfully!\n");

    return 0;
}