//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 
#define MAX_WORD_LEN 100 
#define MAX_WORDS 1000
 
struct word_freq {
    char* word;
    int count;
};
 
void strip_punct(char* s);
void add_word(char* word, struct word_freq* wf_arr, int* p_ct);
int cmp_word_freq(const void* vp1, const void* vp2);
 
int main(int argc, char** argv)
{
    /* read input file */
    if (argc < 2) {
        fprintf(stderr, "%s: missing input file\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE* f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "%s: can't open %s for reading\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }
 
    /* initialize array of word frequencies */
    struct word_freq wf_arr[MAX_WORDS] = {{NULL, 0}};
    int ct = 0;
 
    /* loop over words in input file */
    char word[MAX_WORD_LEN];
    while (fscanf(f, "%s", word) == 1) {
        strip_punct(word);
        if (strlen(word) > 0 && !isdigit(word[0]))
            add_word(word, wf_arr, &ct);
    }
 
    /* sort array by word frequency */
    qsort(wf_arr, ct, sizeof(struct word_freq), cmp_word_freq);
 
    /* print word frequency list */
    for (int i = 0; i < ct; ++i)
        printf("%s\t%d\n", wf_arr[i].word, wf_arr[i].count);
 
    fclose(f);
    return EXIT_SUCCESS;
}
 
void strip_punct(char* s)
{
    char* p = s;
    while (*p) {
        if (ispunct((unsigned char)*p))
            memmove(p, p+1, strlen(p+1)+1);
        else
            ++p;
    }
}
 
void add_word(char* word, struct word_freq* wf_arr, int* p_ct)
{
    int i;
    for (i = 0; i < *p_ct; ++i)
        if (strcmp(word, wf_arr[i].word) == 0) {
            ++wf_arr[i].count;
            return;
        }
    if (*p_ct == MAX_WORDS) {
        fprintf(stderr, "Too many words\n");
        exit(EXIT_FAILURE);
    }
    wf_arr[i].word = strdup(word);
    wf_arr[i].count = 1;
    ++*p_ct;
}
 
int cmp_word_freq(const void* vp1, const void* vp2)
{
    const struct word_freq* wp1 = vp1;
    const struct word_freq* wp2 = vp2;
    if (wp2->count != wp1->count)
        return wp2->count - wp1->count;
    else
        return strcmp(wp1->word, wp2->word);
}