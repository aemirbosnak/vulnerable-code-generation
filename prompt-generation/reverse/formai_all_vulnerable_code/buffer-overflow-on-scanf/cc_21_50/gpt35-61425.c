//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int main() {
    char json[MAX], key[MAX], val[MAX], c;
    int len, i = 0, j = 0, k = 0, is_key = 1, num = 0, is_float = 0, is_neg = 0;
    printf("Enter the JSON string: ");
    scanf("%[^\n]", json);
    len = strlen(json);
    printf("{");
    while(i < len) {
        if(json[i] == '{' || json[i] == ',' || json[i] == '}') {
            if(strlen(key) > 0) {
                printf("\"%s\": ", key);
                memset(key, 0, sizeof(key));
            }
            if(strlen(val) > 0) {
                if(is_float) {
                    if(is_neg) {
                        printf("-");
                        is_neg = 0;
                    }
                    printf("%d.", num);
                    int dec = atoi(val);
                    printf("%d", dec);
                    is_float = 0;
                    num = 0;
                }
                else if(!isdigit(val[0])) {
                    printf("\"%s\"", val);
                }
                else {
                    if(is_neg) {
                        printf("-");
                        is_neg = 0;
                    }
                    printf("%s", val);
                    num = 0;
                }
                memset(val, 0, sizeof(val));
            }
            if(json[i] == '}') {
                printf("}");
            }
            else {
                printf(",");
            }
            is_key = 1;
            i++;
        }
        else if(json[i] == '"') {
            i++;
            j = 0;
            while(json[i] != '"' && i < len) {
                key[j++] = json[i++];
            }
            is_key = 0;
            i++;
        }
        else if(json[i] == ':') {
            is_key = 0;
            i++;
        }
        else if(json[i] == '-' && is_key == 0 && !isdigit(json[i+1])) {
            is_neg = 1;
            i++;
        }
        else if(json[i] == '-' && is_key == 0 && isdigit(json[i+1])) {
            is_float = 1;
            i++;
        }
        else if(json[i] == '.') {
            is_float = 1;
            i++;
        }
        else if(is_key == 0 && !isdigit(json[i])) {
            i++;
        }
        else if(is_key == 0 && isdigit(json[i])) {
            num = (num * 10) + (json[i] - '0');
            i++;
        }
        else if(is_key == 0 && is_float == 1 && isdigit(json[i])) {
            num = (num * 10) + (json[i] - '0');
            i++;
        }
        else if(is_key == 0 && is_float == 1 && !isdigit(json[i])) {
            val[k] = '\0';
            is_float = 0;
            k = 0;
        }
        else {
            val[k++] = json[i++];
        }
    }
    return 0;
}