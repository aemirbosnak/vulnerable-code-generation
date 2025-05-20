//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char filename[20];
    int start;
    int end;
} file;

int main(){
    int i, choice, count=0, size, start, end, flag;
    file f[10];
    printf("Welcome to File Allocation Simulator\n");
    while(1){
        printf("\nMenu:\n1. Add a new file\n2. Delete a file\n3. Display the file allocation table\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the size of the new file: ");
                scanf("%d", &size);
                flag=0;
                for(i=0; i<count; i++){
                    if(f[i].end-f[i].start>=size){
                        flag=1;
                        start=f[i].start;
                        end=f[i].start+size;
                        printf("File %d has been allocated from %d to %d.\n", count+1, start, end-1);
                        //updating file information
                        for(int j=count; j>i; j--){
                            f[j].start=f[j-1].start;
                            f[j].end=f[j-1].end;
                        }
                        f[i].start=end;
                        strcpy(f[i].filename, "");
                        f[count].start=start;
                        f[count].end=end;
                        printf("Enter the name of the new file: ");
                        scanf("%s", &f[count].filename); //adding new file
                        count++;
                        break;
                    }
                }
                if(flag==0)
                    printf("File can not be allocated. Fragmentation occurs!\n");                  
                break;
            case 2:
                printf("Enter the name of the file to be deleted: ");
                char name[20];
                scanf("%s", name);
                for(i=0; i<count; i++){
                    if(strcmp(name, f[i].filename)==0){
                        printf("File %s deleted.\n", f[i].filename);
                        //updating file information
                        for(int j=i; j<count-1; j++){
                            f[j].start=f[j+1].start;
                            f[j].end=f[j+1].end;
                            strcpy(f[j].filename, f[j+1].filename);
                        }
                        count--;
                        break;
                    }
                }
                if(i==count)
                    printf("File not found.\n");
                break;
            case 3:
                printf("File Allocation Table:\n");
                printf("File Name\tStart Block\tEnd Block\n");
                for(i=0; i<count; i++)
                    printf("%s\t\t%d\t\t%d\n", f[i].filename, f[i].start, f[i].end-1);
                break;
            case 4:
                printf("Thanks for using the program!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}