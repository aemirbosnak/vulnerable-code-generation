//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Struct for Encoding*/
struct RunLengthEncoding
{
    char character;
    int count;
};

/*Function to encode a string*/
void encode(char* input_str, char* output_str)
{
    struct RunLengthEncoding rle;

    int input_len = strlen(input_str), output_len=0;
    
    /*Iterate over each character of input string*/
    for(int i=0;i<input_len;i++)
    {
        rle.character = input_str[i];
        rle.count = 1;
        
        /*Count the number of consecutive characters*/
        while((i+1)<input_len && input_str[i]==input_str[i+1])
        {
            i++;
            rle.count++;
        }
        /*Add the encoded character and its count to the output string*/
        output_str[output_len++] = rle.character;
        output_str[output_len++] = (char)rle.count+'0';
    }
    output_str[output_len] = '\0';
}

/*Function to decode a string*/
void decode(char* input_str, char* output_str)
{
    int input_len = strlen(input_str), output_len=0;

    /*Iterate over each character of input string*/
    for(int i=0;i<input_len;i+=2)
    {
        /*Add the character 'count' times to the output string*/
        int count = input_str[i+1]-'0';
        for(int j=0;j<count;j++)
            output_str[output_len++] = input_str[i];
    }
    output_str[output_len] = '\0';
}

/*Driver function*/
int main()
{
    char input_str[100], output_str[100];
    printf("Enter a string to encode: ");
    scanf("%s", input_str);

    /*Encode the input string*/
    encode(input_str, output_str);
    printf("Encoded string: %s\n", output_str);

    /*Decode the encoded string*/
    decode(output_str, input_str);
    printf("Decoded string: %s\n", input_str);

    return 0;
}