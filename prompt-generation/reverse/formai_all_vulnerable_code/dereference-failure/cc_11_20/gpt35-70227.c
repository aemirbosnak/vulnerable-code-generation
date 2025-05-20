//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void beautifyHTML(char *html) {
    int len = strlen(html);
    char *beauty_html = malloc(len+1);
    memset(beauty_html, 0, len+1);
    int indent = 0, i=0, j=0;
    
    while(i < len) {
        if(html[i] == '<') {
            if(html[i+1] == '/') {
                indent -= 2;
            }
            for(int k=0;k<indent;k++) {
                beauty_html[j++] = ' ';
            }
            beauty_html[j++] = html[i++];
            while(html[i] != '>') {
                beauty_html[j++] = html[i++];
            }
            beauty_html[j++] = html[i++];
            beauty_html[j++] = '\n';
            
            if(html[i] != '\0' && html[i] != '<') {
                for(int k=0;k<indent;k++) {
                    beauty_html[j++] = ' ';
                }
                while(html[i] != '<') {
                    beauty_html[j++] = html[i++];
                }
                beauty_html[j++] = '\n';
            }
            else if(html[i] == '<') {
              beauty_html[j++] = '\n';
            }
        }
        else if(html[i] == '>') {
            beauty_html[j++] = html[i++];
            beauty_html[j++] = '\n';
            for(int k=0;k<indent;k++) {
                beauty_html[j++] = ' ';
            }
            while(html[i] != '<') {
                beauty_html[j++] = html[i++];
            }
        }
        else {
            beauty_html[j++] = html[i++];
        }
      
        if(html[i] == '\0' || (html[i] == '<' && (html[i+1] == '/' || html[i+1] == '!'))) {
            beauty_html[j] = '\0';
            break;
        }
        else if(html[i] == '<' && html[i+1] != '/') {
            indent += 2;
        }
        else if(html[i] == ' ') {
            beauty_html[j++] = ' ';
            while(html[i] == ' ') {
                i++;
            }
        }
    }
    printf("HTML Code after beautification:\n\n%s", beauty_html);
    free(beauty_html);
}

int main() {
    char *html = "<html><head><title>Page Title</title></head><body><p>Some text here.</p><img src='image.jpeg'/></body></html>";
    printf("HTML Code before beautification:\n\n%s\n", html);
    beautifyHTML(html);
    return 0;
}