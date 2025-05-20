//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 100 // Maximum length of a JSON string
#define STACK_SIZE 100 // Maximum size of stack for JSON objects

/*
    Structure for a JSON stack, which is used to store the JSON objects
*/
struct json_stack
{
    char* key; // key of the object
    char* value; // value of the object
}json_stack[STACK_SIZE]; // Maximum size of the stack

int top = -1; // top of the stack

/*
    Function to push JSON object onto the stack
*/
void push(char* key, char* value)
{
    // Check if stack is full
    if(top == STACK_SIZE-1)
    {
        printf("Stack overflow\n");
        exit(0);
    }   
    
    top++; // increment top
    json_stack[top].key = key; // store key
    json_stack[top].value = value; // store value
}

/*
    Function to pop JSON object from the stack
*/
void pop()
{
    // Check if stack is empty
    if(top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }   
    
    top--; // decrement top
}

/*
    Function to check if a character is a valid JSON delimiter
*/
int is_delim(char c)
{
    if(c == ' ' || c == '\t' || c == '\n' || c == '\r' 
    || c == ',' || c == ':' || c == '[' || c == ']' || c == '{' || c == '}')
        return 1;
    return 0;
}

/*
    Function to parse JSON string and create JSON objects onto the stack
*/
void parse_json(char* json_str)
{
    char* key = NULL;
    char* value = NULL;
    char* token = strtok(json_str, "{}[],\"\n\r\t"); // tokenize the JSON string

    while(token != NULL)
    {
        if(strcmp(token, ":") == 0) // store key
            key = value;    
        else if(strcmp(token, "{") == 0) // push object onto the stack
            push(key, token);
        else if(strcmp(token, "}") == 0) // pop object from stack
            pop();
        else if(strcmp(token, ",") != 0) // store value
            value = token;

        token = strtok(NULL, "{}[],\"\n\r\t"); // get next token
    }
}

int main()
{
    char json_str[MAX_LEN];

    printf("Enter a JSON string: ");
    fgets(json_str, MAX_LEN, stdin); // read JSON string

    json_str[strlen(json_str)-1] = '\0'; // remove newline character

    parse_json(json_str); // parse the JSON string and create stack

    // print the JSON objects in the stack
    printf("\nJSON Objects: \n");
    for(int i=top; i>=0; i--)
    {
        printf("Key: %s\tValue:%s\n", json_stack[i].key, json_stack[i].value);
    }

    return 0;
}