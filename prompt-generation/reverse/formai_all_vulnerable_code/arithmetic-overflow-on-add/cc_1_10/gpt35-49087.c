//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_JSON_SIZE 1024

typedef struct {
    char *key;
    char *value;
} JSONNode;

void parseJSON(char *jsonString, JSONNode *jsonNodes, int *numNodes){
    char *keyStart, *keyEnd, *valStart, *valEnd;
    int in_quotes = 0, in_key = 1, num_nodes = 0;
    keyStart = jsonString;

    while(*jsonString){
        if(*jsonString == '\"'){
            if(in_key){
                keyEnd = jsonString-1;
                in_key = 0;
                in_quotes = 1;
            }
            else if(in_quotes){
                 valEnd = jsonString-1;
                 jsonNodes[num_nodes].key = strndup(keyStart, keyEnd-keyStart+1);
                 jsonNodes[num_nodes].value = strndup(valStart, valEnd-valStart+1);
                 num_nodes++;
                 in_key = 1;
                 in_quotes = 0;
             }
         }
         else if (*jsonString == ':'){
             valStart = jsonString+1;
         }

         jsonString++;
     }

     *numNodes = num_nodes;
 }

int main(){
    char jsonString[MAX_JSON_SIZE] = "{\"name\": \"John\", \"age\":21, \"address\": {\"street\":\"123 Main St\", \"city\":\"Chicago\"}}";
    JSONNode jsonNodes[10];
    int num_nodes;

    parseJSON(jsonString, jsonNodes, &num_nodes);

    for(int i=0; i<num_nodes;i++){
        printf("Key: %s, Value: %s\n", jsonNodes[i].key, jsonNodes[i].value);
    }

    return 0;
}