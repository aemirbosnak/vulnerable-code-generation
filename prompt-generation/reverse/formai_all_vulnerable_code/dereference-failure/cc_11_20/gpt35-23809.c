//FormAI DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data[50];
    struct Node *next;
}node;

void insert(node **head, char *data)
{
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->next = *head;
    *head = new_node;
}

int main(){
    char str[100];
    printf("Enter C code to parse:\n");
    fgets(str, 100, stdin);
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='/' && str[i+1]=='/'){
            i+=2;
            while(str[i]!='\n' && str[i]!='\0') i++;
            printf("Comment: ");
            for(int j=2; j<i; j++) printf("%c", str[j]);
            printf("\n");
        }
        else if(str[i]=='/' && str[i+1]=='*'){
            i+=2;
            while(str[i]!='\0' && !(str[i]=='*' && str[i+1]=='/')) i++;
            printf("Comment: ");
            for(int j=2; j<i; j++) printf("%c", str[j]);
            printf("\n");
            i+=2;
        }
        else if(str[i]=='#'){
            char header[50];
            int j=0;
            i++;
            while(str[i]!=' ' && str[i]!='\n' && str[i]!='\0'){
                header[j] = str[i];
                i++;
                j++;
            }
            header[j] = '\0';
            printf("Header file: %s\n", header);
        }
        else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            char var[50];
            int j=0;
            while(str[i]!=' ' && str[i]!='(' && str[i]!='\n' && str[i]!='\0'){
                var[j] = str[i];
                i++;
                j++;
            }
            var[j] = '\0';
            if(strcmp(var, "int")==0 || strcmp(var, "char")==0 || strcmp(var, "float")==0 || strcmp(var, "double")==0){
                j=0;
                char v[50];
                while(str[i]!=';' && str[i]!='\0'){
                    v[j] = str[i];
                    i++;
                    j++;
                }
                v[j] = '\0';
                printf("%s: %s\n", var, v);
            }
            else if(str[i]=='('){
                node* head = NULL;
                j=0;
                while(str[i]!=')'){
                    if(str[i]==','){
                        var[j] = '\0';
                        insert(&head, var);
                        j=0;
                    }
                    else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
                        var[j] = str[i];
                        j++;
                    }
                    i++;
                }
                var[j] = '\0';
                insert(&head, var);
                printf("Function call: %s\n", var);
                printf("Parameters:\n");
                node* current = head;
                while(current){
                    printf("%s\n", current->data);
                    current = current->next;
                }
            }
            else{
                printf("Unknown syntax\n");
                break;
            }
        }
        i++;
    }
    return 0;
}