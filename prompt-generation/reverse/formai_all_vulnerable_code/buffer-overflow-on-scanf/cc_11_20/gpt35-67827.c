//FormAI DATASET v1.0 Category: Digital Diary ; Style: innovative
#include<stdio.h>
#include<string.h>

struct diaryEntry{
    char date[20];
    char title[50];
    char content[500];
};

int main(){
    FILE *diaryFile;
    int choice, isMatched=0, i=0, j=0;
    char searchTitle[50];
    struct diaryEntry entry;
    char confirm;

    printf("\n-------------Welcome to Digital Diary-------------\n\n");

    do{
        printf("\nPlease choose an option:\n");
        printf("1. Write new entry\n");
        printf("2. Search for an entry\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                diaryFile = fopen("diaryFile.txt", "a");

                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf("%s", entry.date);
                printf("Enter a title for the entry: ");
                getchar();
                fgets(entry.title, 50, stdin);
                printf("Start writing your entry (Press Enter then type 'DONE' to finish):\n");
                do{
                    fgets(entry.content, 500, stdin);
                    if(strcmp(entry.content, "DONE\n")!=0)
                        fprintf(diaryFile, "%s", entry.content);
                }while(strcmp(entry.content, "DONE\n")!=0);

                fprintf(diaryFile, "\n");
                fclose(diaryFile);

                printf("\n----Entry added successfully!----\n");
                break;
            
            case 2:
                diaryFile = fopen("diaryFile.txt", "r");

                if(diaryFile==NULL){
                    printf("\n----No entries found!---\n");
                    break;
                }

                printf("\nEnter the title to search: ");
                getchar();
                fgets(searchTitle, 50, stdin);

                while(!feof(diaryFile)){
                    fscanf(diaryFile, "%[^\n]\n", entry.title); //reading the title from file
                    
                    //checking if title from file matches input search title
                    while(searchTitle[i]!='\0' && entry.title[j]!='\0'){
                        if(searchTitle[i]!=entry.title[j]){
                            isMatched=0;
                            break;
                        }
                        i++;
                        j++;
                        isMatched=1;
                    }

                    //if matched print the whole entry
                    if(isMatched==1){
                        printf("\nTitle: %s", entry.title);
                        fscanf(diaryFile, "%[^\n]\n", entry.date);
                        printf("Date: %s\n", entry.date);

                        while(!feof(diaryFile)){
                            fscanf(diaryFile, "%[^\n]\n", entry.content);

                            if(strcmp(entry.content, "")==0 || strcmp(entry.content, "\n")==0)
                                break;

                            printf("%s", entry.content);
                        }
                    }

                    //reset variables for next iteration
                    isMatched=0;
                    i=0;
                    j=0;
                }

                fclose(diaryFile);

                if(isMatched==0)
                    printf("\n----No entries found with this title!----\n");
                break;

            case 3:
                printf("\nAre you sure you want to exit?(Y/N)\n");
                scanf(" %c", &confirm);
                if(confirm=='Y' || confirm=='y')
                    printf("\n----Exiting Digital Diary----\n");
                else{
                    choice=0;
                    printf("\n----Taking you back to menu----\n");
                }
                break;

            default:
                printf("\n----Invalid choice! Please try again----\n");
                break;
        }
    }while(choice!=3);

    return 0;
}