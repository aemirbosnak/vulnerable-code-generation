//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1024
#define MAX_TOKENS 2048

int string_compress(char *input_string,char *output_string);

int main(int argc, char const *argv[])
{
	char input_string[MAX_STRING_LEN];
	char output_string[MAX_STRING_LEN];
	memset(input_string,0,sizeof(input_string));
	memset(output_string,0,sizeof(output_string));
	
	printf("Enter the string to be compressed: ");
	fgets(input_string,MAX_STRING_LEN,stdin);

	/* Remove trailing newline character */
	if(input_string[strlen(input_string) - 1] == '\n')
    	input_string[strlen(input_string) - 1] = '\0';

    /* Compress the string */
    string_compress(input_string,output_string);

    /* Print the compressed string */
    printf("Compressed string: %s\n", output_string);

	return 0;
}

/* Function which compresses a string */
int string_compress(char *input_string,char *output_string)
{
	/* Variables */
	char tokens[MAX_TOKENS][MAX_STRING_LEN];
    int current_token_length = 1;
    int current_token_count = 0;
    int i,j,k;

    /* Start tokenizing the string */
    for(i=0;i<(int)strlen(input_string);i++)
    {
    	/* Check if current character is same as previous character */
    	if(i > 0 && input_string[i] == input_string[i-1])
    	{
    		/* Add character to current token */
    		tokens[current_token_count][current_token_length - 1] = input_string[i];
    		current_token_length++;
    	}
    	else
    	{
    		/* Add the current token to the list of tokens */
    		current_token_count++;

    		/* If the current token count exceeds the limit, exit */
    		if(current_token_count > MAX_TOKENS)
    		{
    			/* return -1 indicating failure */
    			return -1;
    		}

    		/* Reset the current token length */
    		current_token_length = 1;

    		/* Add the current character to the new token */
    		tokens[current_token_count-1][0] = input_string[i];
    	}
    }

    /* Compose the output string */
    k = 0;
    for(i=0;i<current_token_count;i++)
    {
    	/* Add the length of the current token */
    	sprintf(&output_string[k],"%d",strlen(tokens[i]));
    	k += strlen(&output_string[k]);

    	/* Add the character from the current token */
    	if(tokens[i][0] != '\0')
    	{
    		sprintf(&output_string[k],"%c",tokens[i][0]);
    		k++;
    	}
    }

    /* Return 0 indicating success */
    return 0;
}