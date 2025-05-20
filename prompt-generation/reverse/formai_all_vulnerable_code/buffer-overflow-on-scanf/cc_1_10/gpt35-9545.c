//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct Record
{
    int key;
    int data;
};

struct Index
{
    int key;
    int address;
};

void read_records(struct Record records[], int *n)
{
    printf("Enter number of records: ");
    scanf("%d", n);
    printf("\nEnter records [key data]: \n");
    for(int i=0;i<*n;i++)
    {
        scanf("%d%d",&records[i].key, &records[i].data);
    }
}

void print_records(struct Record records[], int n)
{
    printf("\nRecords:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n", records[i].key, records[i].data);
    }
}

void print_index(struct Index index[], int n)
{
    printf("\nIndex:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n", index[i].key, index[i].address);
    }
}

void create_index(struct Index index[], struct Record records[], int n)
{
    for(int i=0;i<n;i++)
    {
        index[i].key=records[i].key;
        index[i].address=i;
    }
    printf("\nIndex created successfully!\n");
}

int binary_search(struct Record records[], int l, int r, int key)
{
    if(r>=l)
    {
        int mid = l+(r-l)/2;
        if(records[mid].key==key)
        {
            return mid;
        }
        if(records[mid].key>key)
        {
            return binary_search(records, l, mid-1, key);
        }
        return binary_search(records, mid+1, r, key);
    }
    return -1;
}

void search_record(struct Record records[], struct Index index[], int n)
{
    int key, pos;
    printf("\nEnter key to be searched: ");
    scanf("%d", &key);
    pos=binary_search(records, 0,n-1,key);
    if(pos==-1)
    {
        printf("\nRecord not found!\n");
    }
    else
    {
        printf("\nRecord found at address %d\n", pos);
        printf("\nRecord is %d %d\n", records[pos].key, records[pos].data);
    }
}

int main()
{
    struct Record records[MAX];
    struct Index index[MAX];
    int n,ch;
    read_records(records, &n);
    create_index(index, records, n);
    do
    {
        printf("\n\nMenu\n1. Print Records\n2. Print Index\n3. Search Record\n4. Exit\n\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: print_records(records, n);
                    break;
            case 2: print_index(index, n);
                    break;
            case 3: search_record(records, index,n);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }while(ch!=4);
    return 0;
}