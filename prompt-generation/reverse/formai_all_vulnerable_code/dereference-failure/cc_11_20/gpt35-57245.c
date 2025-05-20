//FormAI DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_indentation(char *output, int indent_level) {
    int i;
    for(i=0; i<indent_level; i++) {
        strcat(output, "\t");
    }
}

int main() {
    FILE *input_file, *output_file;
    char ch, line[1000], output[20000];
    int i, indent_level=0, len, inside_tag=0, inside_comment=0, inside_attribute=0;
    
    input_file = fopen("input.html", "r");
    output_file = fopen("output.html", "w");
    
    if(input_file == NULL) {
        printf("Error in opening input file...");
        exit(0);
    }
    
    if(output_file == NULL) {
        printf("Error in opening output file...");
        exit(0);
    }
    
    while(!feof(input_file)) {
        fgets(line, 1000, input_file);
        len = strlen(line);
        
        for(i=0; i<len; i++) {
            ch = line[i];
            
            if(ch == '<') {
                inside_tag = 1;
                
                if(line[i+1] == '/') {
                    inside_tag = 2;
                }
                
                if(line[i+1] == '!') {
                    inside_comment = 1;
                }
            }
            
            if(ch == '"') {
                inside_attribute = !inside_attribute;
            }
            
            if(ch == '>') {
                inside_tag = 0;
                inside_comment = 0;
            }
            
            if(ch == '\n') {
                add_indentation(output, indent_level);
            }
            
            strcat(output, &ch);
            
            if(ch == '/' && inside_tag == 1 && !inside_attribute && !inside_comment) {
                char next_ch = line[i+1];
                if(next_ch == '>') {
                    strcat(output, "\n");
                }
            }
            
            if(ch == '/' && inside_tag == 2 && !inside_comment) {
                strcat(output, "\n");
            }
            
        }
        
        if(strchr(line, '>') != NULL) {
            indent_level++;
        }
        
        if(strchr(line, '<') != NULL && strchr(line, '>') != NULL && strchr(line, '/') == NULL) {
            indent_level--;
        }
    }
    
    fprintf(output_file, "%s", output);
    
    printf("HTML code formatted successfully!");
    
    fclose(input_file);
    fclose(output_file);

    return 0;
}