//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    char ch, file_input[20], file_output[20], secret_string[30], secret_character;
    int i=0, j=0, k=0;
    FILE *input_file, *output_file;

    printf("Enter the name of input file:\n");
    scanf("%s", file_input);

    printf("Enter the name of output file:\n");
    scanf("%s", file_output);

    input_file = fopen(file_input, "r");
    output_file = fopen(file_output, "w");

    if(input_file == NULL) {
        printf("Error: Cannot open %s\n", file_input);
        exit(1);
    }

    if(output_file == NULL) {
        printf("Error: Cannot open %s\n", file_output);
        exit(1);
    }

    printf("Enter the secret message:\n");
    scanf("%s", secret_string);

    while((ch=fgetc(input_file))!=EOF) {
        if(isalpha(ch) || isspace(ch)) {     //encode string
            if(secret_string[j]=='\0') {
                j=0;
            }
            secret_character = secret_string[j];
            j++;

            if(isalpha(ch) && islower(ch)) {
                ch = (((ch-97)+(tolower(secret_character)-96))%26)+97;
            }
            else if(isalpha(ch) && isupper(ch)) {
                ch = (((ch-65)+(toupper(secret_character)-64))%26)+65;
            }
            fputc(ch, output_file);
        }
        else {    //do not encode special characters and digits
            fputc(ch, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);

    input_file = fopen(file_output, "r");
    printf("The encoded message is:\n");
    while((ch=fgetc(input_file))!=EOF) {
        printf("%c", ch);
    }

    fclose(input_file);

    output_file = fopen(file_output, "r");
    if(output_file == NULL) {
        printf("Error: Cannot open %s\n", file_output);
        exit(1);
    }

    printf("\nThe decoded message is:\n");
    while((ch=fgetc(output_file))!=EOF) {
        if(isalpha(ch) || isspace(ch)) {     //decode string
            secret_character = secret_string[k];
            k++;

            if(isalpha(ch) && islower(ch)) {
                ch = (((ch-97)-(tolower(secret_character)-96)+26)%26)+97;
            }
            else if(isalpha(ch) && isupper(ch)) {
                ch = (((ch-65)-(toupper(secret_character)-64)+26)%26)+65;
            }
            printf("%c", ch);
        }
        else {    //do not decode special characters and digits
            printf("%c", ch);
        }
    }

    fclose(output_file);

    return 0;
}