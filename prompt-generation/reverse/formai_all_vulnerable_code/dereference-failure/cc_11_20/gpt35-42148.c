//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A structure to store key-value pairs
struct pair {
    char* key;
    char* value;
};

// A structure to store the parsed JSON data
struct json_data {
    int size;
    struct pair* data;
};

// A function to parse the JSON data
struct json_data* parse_json(const char* json_str) {
    // Allocate memory for the parsed data
    struct json_data* data = (struct json_data*)malloc(sizeof(struct json_data));
    data->size = 0;
    data->data = NULL;
    
    // Find the size of the JSON string
    int len = strlen(json_str);
    
    // Traverse the JSON string
    for(int i=0;i<len;i++) {
        // Check if the current character is a key-value separator
        if(json_str[i]==':') {
            // Check if the key exists
            if(data->size>0 && data->data[data->size-1].key==NULL) {
                printf("Invalid JSON data: Key not found\n");
                exit(1);
            }
            // Allocate memory for the new pair
            data->data = (struct pair*)realloc(data->data,sizeof(struct pair)*(data->size+1));
            // Extract the key
            int j = i-1;
            while(j>=0 && json_str[j]!='\"') j--;
            if(j<0) {
                printf("Invalid JSON data: Key not found\n");
                exit(1);
            }
            data->data[data->size].key = (char*)malloc(sizeof(char)*(i-j-1));
            strncpy(data->data[data->size].key,json_str+j+1,i-j-1);
            // Extract the value
            j = i+1;
            while(j<len && (json_str[j]==' ' || json_str[j]=='\t' || json_str[j]=='\n' || json_str[j]=='\r')) j++;
            if(j>=len) {
                printf("Invalid JSON data: Value not found\n");
                exit(1);
            }
            if(json_str[j]=='\"') {
                // String value
                j++;
                int k = j;
                while(k<len && json_str[k]!='\"') k++;
                if(k>=len) {
                    printf("Invalid JSON data: String value not terminated\n");
                    exit(1);
                }
                data->data[data->size].value = (char*)malloc(sizeof(char)*(k-j+1));
                strncpy(data->data[data->size].value,json_str+j,k-j);
            }
            else if(json_str[j]>='0' && json_str[j]<='9') {
                // Numeric value
                int k = j;
                while(k<len && (json_str[k]>='0' && json_str[k]<='9')) k++;
                data->data[data->size].value = (char*)malloc(sizeof(char)*(k-j+1));
                strncpy(data->data[data->size].value,json_str+j,k-j);
            }
            else if(json_str[j]=='t' || json_str[j]=='f') {
                // Boolean value
                int k = j;
                while(k<len && (json_str[k]=='t' || json_str[k]=='f')) k++;
                data->data[data->size].value = (char*)malloc(sizeof(char)*(k-j+1));
                strncpy(data->data[data->size].value,json_str+j,k-j);
            }
            else if(json_str[j]=='n') {
                // Null value
                data->data[data->size].value = (char*)malloc(sizeof(char)*5);
                strncpy(data->data[data->size].value,"null",4);
            }
            else {
                printf("Invalid JSON data: Value type not recognized\n");
                exit(1);
            }
            // Increment the size
            data->size++;
        }
        // Check if the current character is a value separator
        else if(json_str[i]==',') {
            // Check if the key-value pair is complete
            if(data->size==0 || data->data[data->size-1].value==NULL) {
                printf("Invalid JSON data: Value not found\n");
                exit(1);
            }
            // Mark the key as not found
            data->data = (struct pair*)realloc(data->data,sizeof(struct pair)*(data->size+1));
            data->data[data->size].key = NULL;
            data->data[data->size].value = NULL;
            data->size++;
        }
        // Check if the current character is an object start/end
        else if(json_str[i]=='{' || json_str[i]=='}') {
            // Do nothing
        }
        // Check if the current character is a key-value delimiter
        else if(json_str[i]=='\"') {
            // Do nothing
        }
        // Invalid character
        else {
            printf("Invalid JSON data: Unexpected character '%c'\n",json_str[i]);
            exit(1);
        }
    }
    // Check if the last value is complete
    if(data->size==0 || data->data[data->size-1].value==NULL) {
        printf("Invalid JSON data: Value not found\n");
        exit(1);
    }
    // Return the parsed data
    return data;
}

// A function to print the parsed JSON data
void print_json(struct json_data* data) {
    printf("{ ");
    for(int i=0;i<data->size;i++) {
        printf("\"%s\": \"%s\"",(data->data[i].key!=NULL?data->data[i].key:"NULL"),(data->data[i].value!=NULL?data->data[i].value:"NULL"));
        if(i<data->size-1) printf(", ");
    }
    printf(" }\n");
}

// The main function
int main() {
    // The JSON string to parse
    const char* json_str = "{\"name\":\"John Doe\",\"age\":25,\"isStudent\":true,\"marks\":[90,85,95],\"address\":{\"street\":\"123 Main St\",\"city\":\"New York\",\"state\":\"NY\"}}";
    // Parse the JSON string
    struct json_data* data = parse_json(json_str);
    // Print the parsed JSON data
    print_json(data);
    // Free the parsed JSON data
    for(int i=0;i<data->size;i++) {
        if(data->data[i].key!=NULL) free(data->data[i].key);
        if(data->data[i].value!=NULL) free(data->data[i].value);
    }
    free(data->data);
    free(data);
    // Exit
    return 0;
}