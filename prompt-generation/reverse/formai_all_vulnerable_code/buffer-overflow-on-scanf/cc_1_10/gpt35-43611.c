//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentiment[100];
    char* pos_words[10]={"love","happy","joyful","good","great","amazing","best","fantastic","magnificent","awesome"};
    char* neg_words[10]={"hate","sad","unhappy","bad","terrible","awful","worst","dreadful","horrible","disgusting"};

    printf("Enter the sentence for sentiment analysis:\n");
    scanf("%[^\n]s",sentiment);

    int pos_count=0, neg_count=0;

    char* word=strtok(sentiment," ");

    while(word!=NULL)
    {
        for(int i=0;i<10;i++)
        {
            if(strcmp(word,pos_words[i])==0)
            {
                pos_count++;
            }
            else if(strcmp(word,neg_words[i])==0)
            {
                neg_count++;
            }
        }

        word=strtok(NULL," ");
    }

    printf("\nSentiment Analysis Result:\n");

    if(pos_count>neg_count)
    {
        printf("The sentence has a positive sentiment.\n");
        printf("The positive word count is %d and the negative word count is %d.\n",pos_count,neg_count);
        printf("O, happy dagger! This is thy sheath. There rust, and let me die.\n");
    }
    else if(neg_count>pos_count)
    {
        printf("The sentence has a negative sentiment.\n");
        printf("The negative word count is %d and the positive word count is %d.\n",neg_count,pos_count);
        printf("But, soft! what light through yonder window breaks?\nIt is the east, and Juliet is the sun.\n");
    }
    else
    {
        printf("The sentence has a neutral sentiment.\n");
        printf("The positive and negative word counts are equal.\n");
        printf("Good night, good night! parting is such sweet sorrow,\nThat I shall say good night till it be morrow.\n");
    }

    return 0;
}