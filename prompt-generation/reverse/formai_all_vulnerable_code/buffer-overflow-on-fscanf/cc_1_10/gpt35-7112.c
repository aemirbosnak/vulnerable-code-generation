//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

struct word {
    char wrd[50];
    int count;
};

struct summary {
   char sentence[1000];
   int score;
};

int is_stop_word(char* word) {
    char stop_words[][50] = {"a", "an", "the", "this", "that", "these", "those", "in", "on", "at", "to", "for", "with", "by", "of", "and", "or"};
    for (int i = 0; i < sizeof(stop_words)/sizeof(stop_words[0]); i++) {
        if(strcmp(stop_words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int count_words(char* sentence) {
    int count = 0;
    char* s = strtok(sentence, " ");
    while(s != NULL) {
        if(strlen(s) > 2 && !is_stop_word(s)) {
            count++;
        }
        s = strtok(NULL, " ");
    }
    return count;
}

int main() {
    FILE* fp = fopen("input.txt", "r");
    char text[SIZE], c;
    int i = 0;
    while(fscanf(fp, "%c", &c) != EOF) {
        text[i++] = c;

        if (i == SIZE - 1) {
            break;
        }
     }
     text[i] = '\0';
     fclose(fp);

     int len = strlen(text);
     for(int i = 0; i < len; i++) {
        if(text[i] == '\n') {
           text[i] = ' ';
        }
     }

     struct word words[SIZE];
     int w_count = 0;
     char* s = strtok(text, " ");
     while(s != NULL) {
         if(strlen(s) > 2 && !is_stop_word(s)) {
             int flag = 0;
             for(int i = 0; i < w_count; i++) {
                 if(strcmp(words[i].wrd, s) == 0) {
                     words[i].count++;
                     flag = 1;
                     break;
                 }
             }
             if(!flag) {
                 strcpy(words[w_count].wrd, s);
                 words[w_count].count = 1;
                 w_count++;
             }
         }
         s = strtok(NULL, " ");
     }

     for(int i = 0; i < w_count; i++) {
        for(int j = i + 1; j < w_count; j++) {
            if(words[i].count < words[j].count) {
                struct word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
     }

     fp = fopen("output.txt", "w");
     struct summary summaries[10];
     int s_count = 0;
     s = strtok(text, ".");
     while(s != NULL) {
         if(count_words(s) > 2) {
            int score = 0;
            char* w = strtok(s, " ");
            while(w != NULL) {
            for(int i = 0; i < w_count; i++) {
                if(strcmp(words[i].wrd, w) == 0) {
                    score += words[i].count;
                    break;
                }
            }
            w = strtok(NULL, " ");
            }
            if(s_count > 0) {
               if(score > summaries[s_count-1].score) {
                  strcpy(summaries[s_count-1].sentence, s);
                  summaries[s_count-1].score = score;
               }
            } else {
              strcpy(summaries[s_count].sentence, s);
              summaries[s_count].score = score;
            }
            if(s_count < 9) {
               s_count++;
            }
         }
         s = strtok(NULL, ".");
     }

     for(int i = 0; i < s_count; i++) {
        fprintf(fp, "%s\n", summaries[i].sentence);
     }
     fclose(fp);
     return 0;
}